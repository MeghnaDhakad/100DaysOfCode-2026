import heapq
n = int(input("Enter the number of meetings: "))

intervals = []
print("Enter start and end time of each meeting:")
for _ in range(n):
    start, end = map(int, input().split())
    intervals.append([start, end])

intervals.sort()
rooms = []

for start, end in intervals:
    if rooms and rooms[0] <= start:
        heapq.heappop(rooms)  # Reuse a room
    heapq.heappush(rooms, end)

print("Minimum conference rooms required:", len(rooms))