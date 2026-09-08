#include <stdio.h>
#include <stdlib.h>

python
import sys

def solve():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    results = []

    for _ in range(t):
        n = int(data[idx]); idx += 1
        tree = list(map(int, data[idx:idx + n]))
        idx += n

        count = 0
        stack = [(0, 0)]

        while stack:
            node_idx, mask = stack.pop()
            if node_idx >= n or tree[node_idx] == -1:
                continue

            digit = tree[node_idx]
            mask ^= (1 << digit)

            left, right = 2 * node_idx + 1, 2 * node_idx + 2
            has_left = left < n and tree[left] != -1
            has_right = right < n and tree[right] != -1

            if not has_left and not has_right:
                if bin(mask).count('1') <= 1:
                    count += 1
            else:
                if has_left:
                    stack.append((left, mask))
                if has_right:
                    stack.append((right, mask))

        results.append(str(count))

    print("\n".join(results))

if __name__ == "__main__":
    solve()

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
