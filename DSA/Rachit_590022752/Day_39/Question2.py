def min_conference_rooms(meetings):
    if not meetings:
        return 0

    starts = sorted([meeting[0] for meeting in meetings])
    ends = sorted([meeting[1] for meeting in meetings])

    rooms = 0
    max_rooms = 0
    i = j = 0
    n = len(meetings)

    while i < n:
        if starts[i] < ends[j]:
            rooms += 1
            max_rooms = max(max_rooms, rooms)
            i += 1
        else:
            rooms -= 1
            j += 1
    return max_rooms

n = int(input("Enter the number of meetings: "))

meetings = []
print("Enter the start and end time of each meeting:")

for _ in range(n):
    start, end = map(int, input().split())
    meetings.append((start, end))

print("Minimum Conference Rooms Required:", min_conference_rooms(meetings))
