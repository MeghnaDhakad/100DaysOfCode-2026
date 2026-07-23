from typing import List

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        target = tickets[k]

        for i in range(len(tickets)):
            if i <= k:
                # People before or at k can buy up to target times
                time += min(tickets[i], target)
            else:
                # People after k can buy only target - 1 times
                time += min(tickets[i], target - 1)

        return time