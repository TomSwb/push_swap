#!/bin/bash
# ^ "shebang": tells the system to run this file with bash

# ============================================================================ #
#  push_swap tester                                                            #
#  Usage: ./tester.sh [size] [runs] [strategy]                                 #
#    ./tester.sh                 -> 100 numbers, 20 runs, default strategy     #
#    ./tester.sh 500 50          -> 500 numbers, 50 runs                       #
#    ./tester.sh 100 20 --simple -> forces a strategy flag                     #
#  Paths can be overridden:  PUSH_SWAP=../push_swap CHECKER=./checker ./tester.sh
# ============================================================================ #

# ------------------------------- Settings ----------------------------------- #

SIZE=${1:-100}                       # 1st argument, or 100 if missing
RUNS=${2:-20}                        # 2nd argument, or 20 if missing
FLAG=${3:-}                          # 3rd argument (strategy flag), or empty
PUSH_SWAP=${PUSH_SWAP:-./push_swap}  # path to your program (env var or default)
CHECKER=${CHECKER:-./checker}  # path to the checker (env var or default)
FAIL_FILE="failed_args.txt"          # where failing inputs are saved to replay them

GREEN="\033[32m"                     # ANSI code: switch text to green
RED="\033[31m"                       # ANSI code: switch text to red
RESET="\033[0m"                      # ANSI code: back to normal color

# ----------------------------- Sanity checks -------------------------------- #

if [ ! -x "$PUSH_SWAP" ]; then       # -x: "exists and is executable"; ! negates it
    echo "push_swap not found or not executable: $PUSH_SWAP"  # explain the problem
    exit 1                           # quit the script with an error code
fi                                   # end of the if block
if [ ! -x "$CHECKER" ]; then         # same check for the checker
    echo "checker not found or not executable: $CHECKER (try chmod +x)"
    exit 1
fi

# ------------------------------- Functions ---------------------------------- #

# Generates $1 unique random ints across the full int range, on one line
gen_args() {
    shuf -i 0-4294967295 -n "$1" \
        | awk '{printf "%.0f\n", $1 - 2147483648}' \
        | tr '\n' ' '
    # shuf: $1 unique numbers in [0, 2^32 - 1] (a range the size of int)
    # awk : shifts each line by 2^31 -> lands in [INT_MIN, INT_MAX]
    #       (inside awk, $1 means "first field of the line", not the script arg)
    #       %.0f prints the number as a plain integer, no scientific notation
    # tr  : replaces newlines with spaces -> everything on one line
}

# Counts the lines of $1, and returns 0 (not 1) for empty output
count_ops() {
    if [ -z "$1" ]; then             # -z: "string is empty"
        echo 0                       # already sorted -> no operation -> 0
    else
        printf '%s\n' "$1" | wc -l   # one operation per line -> line count
    fi
}

# Sends the operations $1 to the checker, with the numbers $2 as arguments
run_checker() {
    if [ -z "$1" ]; then             # no operations at all
        "$CHECKER" $2 < /dev/null    # feed the checker an empty input
    else
        printf '%s\n' "$1" | "$CHECKER" $2   # pipe the ops into the checker
    fi                               # $2 left unquoted ON PURPOSE: bash splits it
}                                    # into separate arguments, one per number

# ------------------------------ Edge cases ---------------------------------- #
# Things the subject requires besides sorting. Run once, before random tests.

echo "=== Edge cases ==="

OUT=$("$PUSH_SWAP" 2>&1)             # no arguments at all; 2>&1 also grabs stderr
if [ -z "$OUT" ]; then               # subject: must display nothing
    echo -e "${GREEN}OK${RESET}  no arguments -> no output"   # -e: interpret \033 colors
else
    echo -e "${RED}KO${RESET}  no arguments -> printed: $OUT"
fi

OUT=$("$PUSH_SWAP" $FLAG 1 2 3 4 5)  # input already sorted
if [ -z "$OUT" ]; then               # smallest list of operations = nothing
    echo -e "${GREEN}OK${RESET}  already sorted -> 0 operations"
else
    echo -e "${RED}KO${RESET}  already sorted -> $(count_ops "$OUT") operations"
fi

# Each string below is an input that must produce "Error" on stderr
for BAD in "1 2 1" "1 a 3" "2147483648" "-2147483649" "1 2 3 1" "++5" "-"; do
    ERR=$("$PUSH_SWAP" $FLAG $BAD 2>&1 >/dev/null)
    # 2>&1 >/dev/null : keep ONLY stderr (stdout thrown away). Order matters!
    if [ "$ERR" = "Error" ]; then    # = compares strings
        echo -e "${GREEN}OK${RESET}  error on: $BAD"
    else
        echo -e "${RED}KO${RESET}  no 'Error' on stderr for: $BAD (got: '$ERR')"
    fi
done

# ----------------------------- Random tests --------------------------------- #

echo
echo "=== $RUNS runs of $SIZE numbers ${FLAG:+(strategy $FLAG)} ==="
# ${FLAG:+text}: prints "text" only if FLAG is not empty

MAX=0                                # biggest operation count seen
MIN=-1                               # smallest one; -1 means "not set yet"
TOTAL=0                              # sum of all counts, for the average
KO=0                                 # number of failed runs
: > "$FAIL_FILE"                     # empty the fail file (":" does nothing,
                                     # "> file" truncates it)

for i in $(seq 1 "$RUNS"); do        # i goes 1, 2, ... RUNS
    ARG=$(gen_args "$SIZE")          # fresh random numbers for this run
    OPS=$("$PUSH_SWAP" $FLAG $ARG)   # run push_swap ONCE, keep its output
    STATUS=$?                        # $? = exit code of the last command
    COUNT=$(count_ops "$OPS")        # number of operations
    RESULT=$(run_checker "$OPS" "$ARG")   # "OK" or "KO" from the checker

    if [ "$STATUS" -ge 128 ]; then   # code >= 128 means killed by a signal
        RESULT="CRASH"               # (segfault = 139, abort = 134...)
    fi

    if [ "$RESULT" = "OK" ]; then
        echo -e "run $i: $COUNT ops ${GREEN}OK${RESET}"
    else
        echo -e "run $i: $COUNT ops ${RED}$RESULT${RESET}"
        KO=$((KO + 1))               # $(( )) = arithmetic
        echo "$ARG" >> "$FAIL_FILE"  # >> appends: keep the input to replay it
    fi

    TOTAL=$((TOTAL + COUNT))         # add to the sum
    if [ "$COUNT" -gt "$MAX" ]; then # -gt: greater than (numbers, not strings)
        MAX=$COUNT
    fi
    if [ "$MIN" -eq -1 ] || [ "$COUNT" -lt "$MIN" ]; then  # first run, or smaller
        MIN=$COUNT                   # || = "or"
    fi
done

# -------------------------------- Summary ----------------------------------- #

echo
echo "=== Summary ==="
echo "min: $MIN   max: $MAX   avg: $((TOTAL / RUNS))   KO: $KO/$RUNS"

if [ "$KO" -gt 0 ]; then             # tell where to find failing inputs
    echo "failing inputs saved in $FAIL_FILE"
fi

# Grade the MAX against the subject thresholds (only defined for 100 and 500)
if [ "$SIZE" -eq 100 ]; then
    PASS=2000; GOOD=1500; EXCELLENT=700        # ";" = several commands on one line
elif [ "$SIZE" -eq 500 ]; then               # elif = else if
    PASS=12000; GOOD=8000; EXCELLENT=5500
fi

if [ -n "$PASS" ]; then              # -n: "string is not empty" -> thresholds set
    if [ "$MAX" -lt "$EXCELLENT" ]; then
        echo -e "${GREEN}excellent${RESET} (< $EXCELLENT)"
    elif [ "$MAX" -lt "$GOOD" ]; then
        echo -e "${GREEN}good${RESET} (< $GOOD)"
    elif [ "$MAX" -lt "$PASS" ]; then
        echo -e "${GREEN}pass${RESET} (< $PASS)"
    else
        echo -e "${RED}fail${RESET} (>= $PASS)"
    fi
fi