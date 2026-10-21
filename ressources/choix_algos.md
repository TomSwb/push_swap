# Theory to chose the best push_swap algorythms
 
**Target: excellent on every flag** → 100 numbers < 700 ops, 500 numbers < 5500 ops.
 
---
 
## O(n²) — `--simple`
**Algorithm: cost-based insertion sort** (cheapest-move insertion, known at 42 as the "Turk" approach)
 
Caveats to hit excellent:
- Plain insertion sort will NOT reach 700. It must be cost-based.
- Push everything to b except 3, sort those 3 directly.
- For every element, compute the cost of all 4 rotation combos: `ra+rb`, `rra+rrb`, `ra+rrb`, `rra+rb`. Same-direction combos share moves through `rr` / `rrr`. Pick the cheapest.
- Always insert the cheapest element first, not the next one in line.
- Finish by rotating the minimum to the top, the shorter way.
- Complexity claim: worst case O(n) rotations per element → O(n²) is a valid upper bound.
## O(n√n) — `--medium`
**Algorithm: chunk sort with √n chunks**
 
Caveats to hit excellent:
- Number of chunks must scale with √n to keep the complexity claim; tune the constant (k·√n), don't hardcode a number.
- Push phase: reach the next element of the current chunk with `ra` or `rra`, whichever is shorter.
- When pushing to b, if the element is in the lower half of its chunk, `rb` it right after. This keeps b roughly ordered and makes the pull-back cheap. Merge that `rb` with a following `ra` as `rr` when possible.
- Pull-back phase: bring back the max, or the second max if it's closer, then fix order with one `sa`.
- Complexity argument must show each pull-back costs at most ~√n (the `rb` trick keeps the current chunk near an end of b). Otherwise the worst case becomes n².
- 500 < 5500 is the hardest part of this one: measure, then tune k.
## O(n log n) — `--complex`
**Algorithm: quicksort with three-way stack partitioning**
 
Caveats to hit excellent:
- Plain radix will NOT reach 5500 (~6800). Don't use it here.
- Split each range into thirds with two pivots (by rank): small → `pb`+`rb` (bottom of b), middle → `pb` (top of b), big → `ra` (stays in a).
- Recursion must track two things: the range of ranks AND its location (top of a, bottom of a, top of b, bottom of b). Each location uses different moves.
- Base cases (≤ 3 elements) need hardcoded optimal moves for each location.
- Merge `rb` + `ra` into `rr` whenever they come back-to-back.
- Avoid rotating groups back when the next step doesn't need it.
- Complexity claim: pivots by rank always split exactly into thirds, each level touches n elements at constant cost, ~log₃(n) levels → O(n log n) even in the worst case.
---
 
## Why not the other algorithms
 
Estimates on random input. The general rule: on stacks, the only cheap access is the 4 ends (top/bottom of a and b). Any algorithm that needs random access, many separate buckets, or fixed full passes pays for it in rotations.
 
### O(n²) alternatives (subject examples: insertion, selection, bubble, min/max extraction)
 
**Selection sort / min-max extraction**
- Each step: rotate the min (or max) to the top the shorter way, then `pb`. On random input it's on average ~n/4 rotations away.
- 100 numbers: ~100 × 25 + 200 pushes ≈ **2,700**. 500 numbers: ≈ **63,500** (fails even the 12,000 minimum).
**Plain insertion sort** (insert the next element, not the cheapest)
- Each insertion rotates b ~n/4 on average, with no choice of which element to move.
- 100 numbers: ≈ **2,500+**.
**Bubble sort**
- Only `sa` swaps, so each pass needs a full rotation of the stack, up to n passes.
- 100 numbers: up to ≈ **10,000**.
### O(n√n) alternatives (subject examples: chunk, block-based partitioning, bucket with √n buckets, range-based)
 
**Bucket sort with √n buckets**
- Needs √n separate places to drop elements into. You only have 4 cheap ends, so you can't keep √n buckets apart.
- The only way to emulate it is to fill one bucket at a time, scanning a for its elements. That *is* chunk sort, so there's nothing to gain.
**Block-based partitioning** (split by position into √n blocks, sort each, then combine)
- Blocks are cut by position, not by value, so after sorting each block you still have to merge √n sorted blocks.
- Merging on stacks means rotating to reach each block's head: extra cost on top of sorting the blocks. Splitting by value (chunk sort) avoids the merge entirely.
**Range-based strategies**
- Same family as chunk sort (a chunk is a value range). Chunk sort is the best-documented, easiest to tune, and the subject names it exactly with √n, which makes the complexity argument simplest.
**Naive chunk sort** (fixed chunk count, no `rb` trick, always pull the max)
- b ends up unordered within each chunk, so pull-backs need long rotations of b.
- Commonly lands around **6,000–8,000** for 500.
### O(n log n) alternatives (subject examples: radix, merge, quick, heap, binary indexed tree)
 
**Binary radix sort (LSD)**
- Each bit = one full pass: n moves (`pb` or `ra`) + `pa` for the ~n/2 pushed. It never adapts to the current order.
- 100 numbers: 7 bits × ~150 ≈ **1,050**. 500 numbers: 9 bits × ~750 ≈ **6,750**. Good, not excellent.
**MSD radix**
- Same number of bit passes, plus it has to keep track of sub-groups like quicksort does. You get quicksort's complexity of bookkeeping with radix's fixed passes: worse than both.
**Merge sort with two stacks**
- Merging needs two sorted runs reachable at the same time. On stacks, every merge level means moving every element (push) and repositioning runs (rotations).
- ~log₂(n) levels × roughly 1.5–2n moves per level → about **1,000–1,400** for 100 and **7,000–9,000** for 500. Typically worse than radix.
**Heap sort**
- A heap needs random access (parent at i/2, children at 2i, 2i+1). On a stack, reaching index i costs up to n rotations, so each sift step is O(n) moves, not O(1).
- You can keep a heap in memory to decide *which* element to move next, but the moves you emit then degenerate into min extraction: ≈ **2,700** for 100.
**Binary indexed tree (Fenwick tree)**
- It's a data structure for counting and prefix sums, not a sorting strategy. It decides nothing about which moves to emit.
- Useful as a helper (e.g. computing the disorder in O(n log n) instead of O(n²), or counting positions), but you still need an actual move strategy on top.
**Two-way quicksort** (one pivot, halves)
- ~log₂(n) levels instead of ~log₃(n), and each split only uses one end of b. More levels → more passes → more moves than the three-way version.
---
 
## How to make sure (the only real guarantee)
No algorithm is mathematically guaranteed to stay under target on every input. The only way to be sure:
- Run each flag on **at least 100 random sets of 100 and 100 random sets of 500** (use `ressources/generator.sh`).
- Check the **maximum** op count, not the average. The evaluator picks random sets; one bad case is enough to drop a tier.
- Verify every output with the checker.
 
