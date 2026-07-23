n = int(input())

intervals = []

for i in range(n):
    s, e = map(int, input().split())
    intervals.append([s, e])

start = []
end = []

for i in intervals:
    start.append(i[0])
    end.append(i[1])

start.sort()
end.sort()

rooms = 0
max_rooms = 0
i = 0
j = 0

while i < n:
    if start[i] < end[j]:
        rooms += 1
        if rooms > max_rooms:
            max_rooms = rooms
        i += 1
    else:
        rooms -= 1
        j += 1

print(max_rooms)