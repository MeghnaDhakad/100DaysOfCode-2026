from collections import deque

n = int(input())

positions = deque(range(n))
result = [0] * n

for card in range(1, n + 1):
    index = positions.popleft()
    result[index] = card

    if positions:
        positions.append(positions.popleft())

print(result)