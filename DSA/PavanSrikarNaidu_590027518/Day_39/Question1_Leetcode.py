from typing import List

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        for i in range(len(tickets)):
            if i <= k:
                # Person i gets a turn in every round up to and including k's last turn
                time += min(tickets[i], tickets[k])
            else:
                # Person i (after k) only gets a turn in rounds BEFORE k's final purchase
                time += min(tickets[i], tickets[k] - 1)
        return time


# ---- Local testing block (for VS Code, not needed on LeetCode) ----
if __name__ == "__main__":
    sol = Solution()

    # Example 1
    print(sol.timeRequiredToBuy([2, 3, 2], 2))    # Expected Output: 6

    # Example 2
    print(sol.timeRequiredToBuy([5, 1, 1, 1], 0))  # Expected Output: 8