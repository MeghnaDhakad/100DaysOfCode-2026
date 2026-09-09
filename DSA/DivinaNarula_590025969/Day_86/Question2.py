# Fractional Knapsack

def fractional_knapsack(values, weights, capacity):
    items = []

    for i in range(len(values)):
        ratio = values[i] / weights[i]
        items.append((ratio, values[i], weights[i]))

    items.sort(reverse=True)

    total_value = 0

    for ratio, value, weight in items:
        if capacity >= weight:
            total_value += value
            capacity -= weight
        else:
            total_value += ratio * capacity
            break

    return total_value


n = int(input("Enter number of items: "))

values = list(map(int, input("Enter values: ").split()))
weights = list(map(int, input("Enter weights: ").split()))

capacity = int(input("Enter knapsack capacity: "))

result = fractional_knapsack(values, weights, capacity)

print("Maximum value:", result)