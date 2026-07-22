# The Card Trick

from collections import deque

n = int(input("Enter n: "))
queue = deque(range(n))

deck = [0] * n

for card in range(1, n + 1):
    position = queue.popleft()
    deck[position] = card

    if queue:
        queue.append(queue.popleft())

print("Initial deck arrangement:", deck)