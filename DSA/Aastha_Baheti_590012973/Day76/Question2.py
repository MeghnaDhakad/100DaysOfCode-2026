def has_euler_trail(n, edges, k):
    degree = [0] * n

    for u, v in edges:
        degree[u] += 1
        degree[v] += 1

    odd = sum(d % 2 for d in degree)

    return odd == 0


# Input
n = int(input())
m = int(input())

edges = []
for _ in range(m):
    u, v = map(int, input().split())
    edges.append((u - 1, v - 1))

k = int(input())

print("true" if has_euler_trail(n, edges, k) else "false")