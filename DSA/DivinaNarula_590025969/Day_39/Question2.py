# Minimum Conference Rooms Required

def min_conference_rooms(intervals):
    n = len(intervals)

    start_times = [interval[0] for interval in intervals]
    end_times = [interval[1] for interval in intervals]

    start_times.sort()
    end_times.sort()

    start = 0
    end = 0
    rooms = 0
    max_rooms = 0

    while start < n:
        if start_times[start] < end_times[end]:
            rooms += 1
            max_rooms = max(max_rooms, rooms)
            start += 1
        else:
            rooms -= 1
            end += 1

    return max_rooms

n = int(input("Enter number of meetings: "))

intervals = []

for i in range(n):
    start, end = map(int, input(f"Enter start and end time for meeting {i + 1}: ").split())
    intervals.append([start, end])

result = min_conference_rooms(intervals)

print("Minimum conference rooms required:", result)