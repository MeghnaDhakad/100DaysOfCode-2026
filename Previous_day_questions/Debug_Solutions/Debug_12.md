<h2 align="center">Week 12 Day 7 (06/09/2026) — Weekly Debug 12</h2>

## 1. The Architect's Bitmask

### Solution

### Bugs Identified

1. **`clearBit()` used OR instead of AND.**
   The buggy code used `mask | ~(1 << pos)`, which sets unwanted bits rather than clearing the selected bit.
   **Fix:** Use `mask & ~(1 << pos)`.

2. **`toggleBit()` used AND instead of XOR.**
   Toggling a bit requires XOR with a mask containing `1` at the target position.
   **Fix:** Use `mask ^ (1 << pos)`.

3. **`countAwakened()` shifted the mask in the wrong direction.**
   The code used `mask << 1`, which moves the bits left and never removes the lowest bit that was just counted.
   **Fix:** Shift right using `mask >> 1`.

4. **`countAwakened()` did not correctly handle negative 32-bit signed masks.**
   The condition `mask > 0` stops immediately for a negative mask, even though a signed 32-bit mask may contain set bits, including bit 31.
   **Fix:** Treat the mask as an unsigned 32-bit value inside the iterative counting logic.

### Fixed Code

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
    // BUG: return mask | ~(1 << pos);
    return mask & ~(1 << pos);
}

// Toggles the bit at position pos
int toggleBit(int mask, int pos) {
    // BUG: return mask & (1 << pos);
    return mask ^ (1 << pos);
}

// Counts number of set bits in mask
int countAwakened(int mask) {
    int count = 0;
    unsigned int uMask = (unsigned int)mask;

    while (uMask > 0) {
        count += uMask & 1u;
        // BUG: mask << 1;
        uMask >>= 1;
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

### Output

```text
1
0
0
0
1
```

### Explanation

- **Set Bit:** `mask | (1 << pos)` creates a mask with `1` at the required position and preserves all other bits.
- **Test Bit:** `mask & (1 << pos)` isolates the requested bit. A non-zero result means the bit is set.
- **Clear Bit:** `mask & ~(1 << pos)` creates a mask with `0` at the target position and `1` elsewhere, clearing only that bit.
- **Toggle Bit:** `mask ^ (1 << pos)` flips the target bit while leaving all other bits unchanged.
- **Count Set Bits:** The lowest bit is checked with `& 1`, then the unsigned mask is shifted right one position. This repeats until all 32 bits have been processed, including masks whose sign bit is set.

### Complexity

- **Time Complexity:** `O(32)` for `countAwakened`, which is `O(1)` because the mask is fixed at 32 bits.
- **Space Complexity:** `O(1)`.
- **Inbuilt Function:** GCC/Clang provide `__builtin_popcount()` for counting set bits, but the challenge requires preserving the iterative bit-by-bit implementation, so the library/compiler intrinsic is not used here.
