def fractional_knapsack(value, weight, capacity):
    items = []

    for i in range(len(value)):
        ratio = value[i] / weight[i]
        items.append((ratio, value[i], weight[i]))

    # Sort by value/weight ratio in descending order
    items.sort(reverse=True)

    total_value = 0.0

    for ratio, val, wt in items:
        if capacity >= wt:
            capacity -= wt
            total_value += val
        else:
            total_value += ratio * capacity
            break

    return total_value


n = int(input())
value = list(map(int, input().split()))
weight = list(map(int, input().split()))
capacity = int(input())

result = fractional_knapsack(value, weight, capacity)

print(int(result) if result.is_integer() else result)