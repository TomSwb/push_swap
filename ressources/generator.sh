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

SIZE=${1:-100}                       # 100 if missing

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

# ----------------------------- Random tests --------------------------------- #

gen_args "$SIZE"          # fresh random numbers for this run

# to use run ARG=$(./gen.sh 500); ./push_swap $ARG | ./checker_linux $ARG