def max_activities(n, start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])

    count = 0
    last_end = -1

    for s, e in activities:
        if s >= last_end:
            count += 1
            last_end = e

    return count


# Sample Input 1
n = 6
start = [1, 3, 0, 5, 8, 5]
end = [2, 4, 6, 7, 9, 9]

print(max_activities(n, start, end))  # 4


# Sample Input 2
n = 4
start = [1, 2, 3, 4]
end = [2, 3, 4, 5]

print(max_activities(n, start, end))  # 4