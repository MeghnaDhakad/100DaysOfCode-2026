# Maximum Number of Activities

def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])

    count = 0
    last_end = float('-inf')

    for start_time, end_time in activities:
        if start_time >= last_end:
            count += 1
            last_end = end_time

    return count


n = int(input("Enter the number of activities: "))

print("Enter the start times:")
start = list(map(int, input().split()))

print("Enter the end times:")
end = list(map(int, input().split()))

print("Maximum number of activities:", max_activities(start, end))