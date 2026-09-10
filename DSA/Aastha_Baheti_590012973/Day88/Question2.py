class Solution:
    def jobSequencing(self, deadline, profit):
        jobs = sorted(zip(profit, deadline), reverse=True)
        max_deadline = max(deadline)
        slots = [False] * (max_deadline + 1)
        total = 0

        for p, d in jobs:
            for j in range(d, 0, -1):
                if not slots[j]:
                    slots[j] = True
                    total += p
                    break

        return total