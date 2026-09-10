def job_sequencing(deadline, profit):
    jobs = []

    for i in range(len(deadline)):
        jobs.append((profit[i], deadline[i]))

    # Sort by profit in descending order
    jobs.sort(reverse=True)

    max_deadline = max(deadline)
    slots = [False] * (max_deadline + 1)

    total_profit = 0

    for p, d in jobs:
        # Find the latest available slot
        for slot in range(d, 0, -1):
            if not slots[slot]:
                slots[slot] = True
                total_profit += p
                break

    return total_profit


n = int(input())
deadline = list(map(int, input().split()))
profit = list(map(int, input().split()))

print(job_sequencing(deadline, profit))