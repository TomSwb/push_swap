*This project has been created as part of the 42 curriculum by [atardy](https://profile-v3.intra.42.fr/users/atardy), [tschwab](https://profile-v3.intra.42.fr/users/tschwab)*

> [!WARNING]
> **DRAFT — remove this box and every TODO box before submitting.**
> 🟦 **TODO (Tom)** · 🟧 **TODO (Alak)** · 🟩 **TODO (both)**


# push_swap

## Description

`push_swap` sorts a list of integers using two stacks, **a** and **b**, and a limited set of operations. The program prints the list of operations that sorts stack **a** in ascending order (smallest on top), trying to use as few operations as possible.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of a / b / both |
| `pa` / `pb` | push the top of b onto a / the top of a onto b |
| `ra` / `rb` / `rr` | rotate a / b / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | reverse rotate a / b / both (last element becomes first) |

The binary embeds four strategies, selectable with a flag:

| Flag | Strategy | Complexity class |
|---|---|---|
| `--simple` | cost-based insertion | O(n²) |
| `--medium` | **🟧 TODO (Alak)** | O(n√n) |
| `--complex` | three-way quicksort | O(n log n) |
| `--adaptive` (default) | picks one of the three from the measured disorder | depends on the regime |

An optional `--bench` mode prints metrics (disorder, strategy, operation counts) to stderr.

> [!NOTE]
> 🟩 **TODO (both):** one or two sentences on what the project taught you / its interest (optional but nice for recruiters)

## Instructions

### Compilation

```bash
make          # builds ./push_swap
make bonus    # builds ./checker (bonus)
make clean    # removes object files
make fclean   # removes object files and the binaries
make re       # fclean + make
```

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <numbers>
```

- Numbers can be given as separate arguments (`./push_swap 3 2 1`) or as one string (`./push_swap "3 2 1"`). The first number is the top of stack a.
- Without arguments the program displays nothing.
- Non-integer arguments, numbers outside the `int` range or duplicates print `Error` on stderr.
- Already sorted input prints no operations.
- Flags can be given in any order; only one strategy flag is allowed.

> [!NOTE]
> 🟩 **TODO (both):** double-check every line above against the final behaviour (mixed formats? "" ?)

### Examples

```bash
$> ./push_swap 2 1 3 6 5 8
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
$> ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

> [!NOTE]
> 🟩 **TODO (both):** paste real outputs from the final build

### Benchmark mode (`--bench`)

After sorting, `--bench` prints 5 lines to **stderr**; the operations stay on **stdout**:

```
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  13
[bench] sa:  0  sb:  0  ss:  0  pa:  5  pb:  5
[bench] ra:  2  rb:  1  rr:  0  rra:  0  rrb:  0  rrr:  0
```

Use `> /dev/null` to hide the operations and see only the metrics (`2> /dev/null` does the opposite). Each command draws a new random list, so the numbers vary a little between runs.

Simple, 100 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' '); ./push_swap --bench --simple $ARG > /dev/null
```

Simple, 500 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap --bench --simple $ARG > /dev/null
```

Medium, 100 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' '); ./push_swap --bench --medium $ARG > /dev/null
```

Medium, 500 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap --bench --medium $ARG > /dev/null
```

Complex, 100 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' '); ./push_swap --bench --complex $ARG > /dev/null
```

Complex, 500 numbers:
```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap --bench --complex $ARG > /dev/null
```

Verify with the checker while saving the metrics to a file:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' '); ./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG; cat bench.txt
```

> [!NOTE]
> 🟩 **TODO (both):** if the checker bonus is done, add a "Checker (bonus)" subsection: usage, OK / KO / Error, example

## Algorithms

### Shared groundwork

**Disorder.** The share of pairs `(i, j)` with `i < j` that are in the wrong order (`a[i] > a[j]`), over all pairs. 0 % = sorted, 100 % = reverse sorted. Stored as an integer ×100 (rounded) so it can be printed with two decimals without floats. Time O(n²) (every pair once), space O(1).

**Ranks.** Before sorting, each number is replaced by its rank `0 … n-1` (`rank_parsing`). All algorithms then work on ranks, so pivots and targets never depend on the actual values. Time O(n²), space O(1) (the rank is stored in each node).

**Data structure.** Each stack is a circular doubly linked list with a wrapper struct (`top`, `size`, counters), so every operation is O(1): a swap changes 6 pointers, a push 4, a rotation only moves `top`.

> [!IMPORTANT]
> 🟧 **TODO (Alak):** add a short explanation of the parsing (string vs arguments, validation, duplicates). 🟩 Both: reread this section.

### Simple — O(n²): cost-based insertion

1. Push everything except 3 numbers to b. While pushing, numbers ranked below the middle are rotated to the bottom of b (`rb`), so b is roughly split in two halves already. This only adds O(n) moves.
2. Sort the 3 numbers left in a directly (at most 2 moves).
3. Repeatedly move back the **cheapest** number of b: for each number in b, compute how many rotations bring it to the top of b and its target position to the top of a, comparing the 4 combinations (`ra`+`rb`, `rra`+`rrb`, `ra`+`rrb`, `rra`+`rb`). Rotations in the same direction are shared as `rr` / `rrr`. Then `pa`.
4. Rotate the smallest number to the top the shorter way.

**Complexity.** n insertions, each costing at most O(n) rotations, and finding the cheapest one scans b: **O(n²) time**. Space: O(1) besides the stacks.

> [!NOTE]
> 🟦 **TODO (Tom):** reword in your own words; add why cheapest-first beats plain insertion

### Medium — O(n√n) 🟧 TODO (Alak)

> [!IMPORTANT]
> 🟧 **TODO (Alak):** technique, steps, complexity argument (time + space), why this one

### Complex — O(n log n): three-way quicksort

1. The whole stack a is one *chunk*: a range of ranks plus its location (top or bottom of a or b).
2. Two pivots split the chunk's range into exact thirds (`min + size/3`, `min + 2·size/3`). Each number is sent to one of the other stack ends depending on its third, so the three parts land in three different places.
3. Recurse on the big, middle and small parts, in that order, each with its new location.
4. Chunks of 3 or fewer are sorted directly. If the 3 numbers are alone in a, plain rotations are used (at most 2 moves); otherwise a sequence that doesn't disturb the numbers below.
5. A chunk at the bottom of a stack it is alone in is treated as being at the top (same nodes), which saves the moves to bring it up.

**Complexity.** Pivots by rank always split into exact thirds, so there are about log₃(n) levels, and each level moves every number a constant number of times: **O(n log n) time, worst case included**. Space: O(log n) for the recursion depth.

> [!NOTE]
> 🟦 **TODO (Tom):** reword; optionally a small diagram of where small / middle / big go

### Adaptive

| Measured disorder | Regime | Method | Class |
|---|---|---|---|
| < 20 % | low | cost-based insertion (Simple) | O(n²) |
| 20 % – 50 % | medium | **🟧 TODO (Alak)** (Medium) | O(n√n) |
| ≥ 50 % | high | three-way quicksort (Complex) | O(n log n) |

Disorder is computed once before sorting. Already-sorted input (0 %) prints nothing.

**Rationale for the thresholds.**

> [!NOTE]
> 🟩 **TODO (both):** explain why these limits (they are the subject's regime bounds) and why each method fits its regime, e.g. why insertion is cheap on nearly sorted input (few numbers far from their place → few rotations per insertion).

**Complexity.** Disorder O(n²) + the chosen method, so the total is bounded by the class of each regime as required. Space as for each method.

> [!NOTE]
> 🟩 **TODO (both):** check this complexity statement together (disorder and ranks are O(n²) in time — say how you count them in the Push_swap model, where only operations count)

### Why not other algorithms

Only the four stack ends are cheap to reach. Anything that needs random access, many separate buckets or fixed full passes pays for it in rotations.

| Algorithm | Problem on two stacks | Approx. ops (100 / 500) |
|---|---|---|
| Selection / min extraction | rotates to the minimum every time | ~2,700 / ~63,500 |
| Plain insertion (not cheapest-first) | ignores the cost of each insertion | ~2,500+ / — |
| Bubble sort | only adjacent swaps | up to ~10,000 / — |
| Binary radix (LSD) | fixed full passes, never adapts | ~1,050 / ~6,750 |
| Merge sort on two stacks | merging needs many rotations | ~1,000–1,400 / ~7,000–9,000 |
| Heap sort | needs random access, degenerates into min extraction | ~2,700 / — |
| Two-way quicksort | log₂ instead of log₃ levels, uses fewer stack ends | more than three-way |
| Bucket sort with √n buckets | can't keep √n buckets apart with 4 ends → becomes chunk sort | — |

> [!NOTE]
> 🟩 **TODO (both):** keep only what you can explain at the defense; add MSD radix / Fenwick tree if useful

## Performance

Targets for the best tier: **< 700** operations for 100 numbers, **< 5500** for 500.

| Strategy | 100 avg / worst | 500 avg / worst |
|---|---|---|
| `--simple` | 568 / 608 | 4572 / 4867 |
| `--medium` | **🟧 TODO (Alak)** | **🟧 TODO (Alak)** |
| `--complex` | 664 / 669 | 4410 / 4427 |
| `--adaptive` (random input) | **🟩 TODO** | **🟩 TODO** |

Small inputs: 3 numbers in at most 2 operations, 5 numbers in 8–11.

> [!NOTE]
> 🟩 **TODO (both):** re-measure everything on the final build, same method for every row (e.g. 100 random inputs each), and state the method here

## Contributions

**atardy**
- **Argument parsing and error handling:** flags, numbers as one string or as separate arguments, integer validation and overflow, duplicates, building and freeing the stacks.
- **Operations:** `sa` `sb` `ss` `pa` `pb`.
- **Medium algorithm**, O(n√n).
- **Checker** (bonus).

**tschwab**
- **Operations:** `ra` `rb` `rr` `rra` `rrb` `rrr`.
- **Disorder and ranks.**
- **Simple and Complex algorithms**, O(n²) and O(n log n).
- **Adaptive dispatch and `--bench`.**

**Both**
- Data structure design, Makefile, README.
- Code reviews through pull requests: both learners can explain every part.

> [!NOTE]
> 🟩 **TODO (both):** check every line; add anything missing (tests, specific fixes…)

## Resources

### References

> [!NOTE]
> 🟩 **TODO (both):** list what you actually used — e.g. the subject PDF, Big-O notation, quicksort / three-way partitioning (CLRS or Sedgewick), articles or tutorials on push_swap strategies, the 42 checker. Real links only.

- 🟩 TODO

### AI

Each learner describes their own use of AI below.

#### tschwab

> [!NOTE]
> 🟦 **TODO (Tom):** add `--bench` to the scope if relevant.

⚠️ Disclaimer: I only ask for actual answers when I realise I am missing theoretical knowledge, e.g. a new syntax or a concept I had not explored before.

I always write my code to the best of my abilities first. AI never wrote my code, and I do not copy-paste from AI into my code. My AI agent is set to guide me as a peer, following the 42 pedagogical philosophy: questions and explanations, short snippets only to show a new syntax, never full solutions.

Everything AI suggested was checked: tested with the checker and the generator, measured against the benchmark targets, and reviewed with my project partner through pull requests.

- `Claude:` (O(n²) `--simple` and O(n log n) `--complex` parts)
	1. Back-and-forth discussion to compare sorting strategies and their trade-offs on two stacks, before choosing cost-based insertion and three-way quicksort.
	2. Checking my reasoning on the complexity of each algorithm in the project's complexity model.
	3. Explaining new syntax and concepts (e.g. enums, passing structs by pointer) with short examples.
	4. Guiding my debugging and optimisation with questions, to bring move counts under the benchmark targets.
	5. Help in learning the git workflow used with my partner: feature branches, rebases, pull requests.
	6. Shell commands to automate tests (random inputs, move counts, checker).
	7. Reviewing the function briefs and README parts I wrote first, for wording and completeness.

#### atardy  🟧

> [!IMPORTANT]
> 🟧 **TODO (Alak):** your own disclaimer — which AI tools, for which tasks, on which parts of the project.

- 🟧 TODO