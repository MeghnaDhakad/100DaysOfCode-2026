<h2 align="center">Week 6 Day 38 (22/07/2026)</h2>

## 1. Number of Students Unable to Eat Lunch
### Solution
```java
import java.util.*;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] count = new int[2]; // count[0] = students wanting circular, count[1] = students wanting square
        for (int s : students) {
            count[s]++;
        }
        
        int i = 0; // pointer into sandwiches stack
        while (i < sandwiches.length) {
            int type = sandwiches[i];
            if (count[type] == 0) {
                // No student left wants this sandwich type -> rest are stuck
                break;
            }
            count[type]--;
            i++;
        }
        
        return count[0] + count[1];
    }
}
```

**Why this works:** Rotating the queue endlessly is equivalent to just repeatedly asking "does any remaining student want the current top sandwich?" If yes, someone eventually gets to the front and takes it (order among students with the same preference doesn't matter). If no, everyone left is stuck forever, so we stop.

**Complexity:** O(n) time, O(1) space.

---

## 2. The Card Trick
### Solution
```java
import java.util.*;

class Solution {
    public int[] deckArrangement(int n) {
        int[] result = new int[n];
        Deque<Integer> positions = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            positions.addLast(i);
        }
        
        int value = 1;
        while (!positions.isEmpty()) {
            // Reveal the position at the front
            int pos = positions.pollFirst();
            result[pos] = value++;
            
            // Move next position to the bottom
            if (!positions.isEmpty()) {
                positions.addLast(positions.pollFirst());
            }
        }
        
        return result;
    }
}
```

**How it works:**

1. Instead of simulating cards, we simulate which slot in the final array would be revealed at each step.
2. `positions` starts as `[0, 1, 2, ..., n-1]` — the indices of the deck.
3. Each iteration: pop the front index (that's where value `value` belongs in the original arrangement), then move the next index to the back (mirroring "take next card to bottom").
4. Assign `1, 2, 3, ...` to those positions as they're revealed, giving the original arrangement.

**Trace for n = 4:**

* positions = [0,1,2,3]
* Reveal 0 → result[0]=1; move 1 to back → [2,3,1]
* Reveal 2 → result[2]=2; move 3 to back → [1,3]
* Reveal 1 → result[1]=3; move 3 to back → [3]
* Reveal 3 → result[3]=4

Result: `[1, 3, 2, 4]` ✅ matches sample output.

**Complexity:** O(n) time, O(n) space.
