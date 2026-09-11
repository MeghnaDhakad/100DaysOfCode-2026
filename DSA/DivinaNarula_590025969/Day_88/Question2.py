# Job Sequencing with Deadlines

def find(parent, slot):
    if parent[slot] == slot:
        return slot

    parent[slot] = find(parent, parent[slot])
    return parent[slot]


def job_sequencing(deadlines, profits):
    jobs = list(zip(deadlines, profits))
    jobs.sort(key=lambda job: job[1], reverse=True)

    max_deadline = max(deadlines)
    parent = list(range(max_deadline + 1))

    total_profit = 0
    jobs_done = 0

    for deadline, profit in jobs:
        available_slot = find(parent, min(deadline, max_deadline))

        if available_slot > 0:
            total_profit += profit
            jobs_done += 1
            parent[available_slot] = find(parent, available_slot - 1)

    return total_profit


deadlines = list(map(int, input("Enter deadlines: ").split()))
profits = list(map(int, input("Enter profits: ").split()))

print("Maximum Profit:", job_sequencing(deadlines, profits))