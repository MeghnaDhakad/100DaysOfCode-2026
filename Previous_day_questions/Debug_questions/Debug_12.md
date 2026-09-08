<h2 align="center">Week 12 Day 7 (06/09/2026) — Weekly Debug 12</h2>

## 1. The Architect's Bitmask

The Matrix is older than you know. Every human connected to it is represented not by a name, but by a single bit - a flicker of one or zero in a 32-bit register we call the "Mainframe Mask." Awakened minds are flagged with a 1. Sleeping minds remain 0.

Neo pulled up the source. The functions were supposed to:
- Flag a mind as "awakened" (set its bit),
- Check if a mind is "awakened" (test its bit),
- Flag a mind back to "sleeping" (clear its bit),
- Flip a mind's state entirely (toggle its bit),
- Count how many minds are currently awakened in the whole Mainframe Mask (population count).

But the code has been patched by so many rogue agents and rebel hackers that it no longer behaves correctly.

Fix it before Smith finds the same flaw twice.

This problem helps build concepts like:
- Bitwise operators
- Bit masking
- Set, clear, test and toggle operations
- Population count

which are important for writing correct and efficient low-level programs.

**Your task:** Identify and fix all bugs in the given code so that it produces the correct output.

### What the Code Must Do

- Correctly set the bit at a given position without disturbing other bits.
- Correctly test whether the bit at a given position is set.
- Correctly clear the bit at a given position without disturbing other bits.
- Correctly toggle the bit at a given position.
- Correctly count the total number of set bits in the mask.
- Preserve bitwise-only operations - no division, modulo loops, or string conversion tricks.

### Constraints

- `pos` will always satisfy `0 <= pos <= 31`.
- `mask` is a 32-bit signed integer.
- Only bitwise operators may be used (`&`, `|`, `^`, `~`, `<<`, `>>`) for bit manipulation.
- The iterative bit-by-bit structure of `countAwakened` must be preserved.
- The solution must work for any mask value, not just the one in `main()`.
- Correct the existing implementation. Do not add new functions.

### Examples

**Output:**
```text
1
0
0
0
1
```

### Buggy Code

```c
#include <stdio.h>

// Sets the bit at position pos
int setBit(int mask, int pos) {
    return mask | (1 << pos);
}

// Tests if the bit at position pos is set
int testBit(int mask, int pos) {
    return (mask & (1 << pos));
}

// Clears the bit at position pos
int clearBit(int mask, int pos) {
    return mask | ~(1 << pos);
}

// Toggles the bit at position pos
int toggleBit(int mask, int pos) {
    return mask & (1 << pos);
}

// Counts number of set bits in mask
int countAwakened(int mask) {
    int count = 0;
    while (mask > 0) {
        count += mask & 1;
        mask << 1;
    }
    return count;
}

int main() {
    int mainframeMask = 0;

    mainframeMask = setBit(mainframeMask, 0); // Neo awakens
    mainframeMask = setBit(mainframeMask, 3); // Morpheus awakens
    mainframeMask = setBit(mainframeMask, 5); // Trinity awakens

    printf("%d\n", testBit(mainframeMask, 3) != 0);
    printf("%d\n", testBit(mainframeMask, 1) != 0);

    mainframeMask = clearBit(mainframeMask, 3); // Morpheus captured
    printf("%d\n", testBit(mainframeMask, 3) != 0);

    mainframeMask = toggleBit(mainframeMask, 5); // Smith overwrites Trinity's slot
    printf("%d\n", testBit(mainframeMask, 5) != 0);

    printf("%d\n", countAwakened(mainframeMask));

    return 0;
}
```
