n = int(input())

cost = 0
total = 0

for _ in range(n):
    a, b, c = map(int, input().split())
    total += c
    
    # Clockwise direction is a -> b if b is the next city
    if b == a % n + 1:
        cost += 0
    else:
        cost += c

print(min(cost, total - cost))