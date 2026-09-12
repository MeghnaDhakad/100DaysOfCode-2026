<h2 align="center">Week 13 Day 89 (11/09/2026)</h2>

## 1. Can Place Flowers (LeetCode #605)

A problem that teaches greedy algorithms for determining whether new flowers can be planted without violating adjacency constraints.

You are given a flowerbed represented as an integer array `flowerbed`, where `1` represents a plot that already contains a flower and `0` represents an empty plot.

Flowers cannot be planted in adjacent plots. You are also given an integer `n` representing the number of new flowers you want to plant.

This problem helps build concepts like:
- Greedy algorithms
- Array traversal
- Local decision making
- Constraint checking

which are important for solving placement and arrangement problems efficiently.

**Your task:** Return `true` if all `n` new flowers can be planted without violating the no-adjacent-flowers rule, otherwise return `false`.

### Input
An integer array and an integer:
- `flowerbed`, where `flowerbed[i]` is `0` if the plot is empty and `1` if it already contains a flower.
- `n`, representing the number of flowers to be planted.

**Constraints:**
- `1 <= flowerbed.length <= 2 * 10^4`
- `flowerbed[i]` is `0` or `1`
- There are no two adjacent flowers in `flowerbed`
- `0 <= n <= flowerbed.length`

### Output
Return `true` if all `n` flowers can be planted without breaking the no-adjacent-flowers rule, otherwise return `false`.

### Examples

**Input:**
```text
flowerbed = [1, 0, 0, 0, 1]
n = 1
```

**Output:**
```text
true
```

---

**Input:**
```text
flowerbed = [1, 0, 0, 0, 1]
n = 2
```

**Output:**
```text
false
```

---

## 2. Buy Two Chocolates

A problem that teaches greedy algorithms for minimizing the cost of selecting two items.

You are given an integer array `prices`, where `prices[i]` represents the price of the `i`-th chocolate, and an integer `money` representing the amount of cash available.

You must buy exactly two chocolates. To spend as little as possible, you should select the two cheapest chocolates available.

If the available money is enough to buy both chocolates, return the remaining money. Otherwise, do not buy anything and return the original amount of money.

This problem helps build concepts like:
- Greedy algorithms
- Finding minimum values
- Array traversal
- Cost optimization

which are important for solving selection and optimization problems efficiently.

**Your task:** Return the amount of money left after buying the two cheapest chocolates. If both chocolates cannot be afforded, return the original value of `money`.

### Input
An integer array and an integer:
- `prices`, where `prices[i]` represents the price of the `i`-th chocolate.
- `money`, representing the amount of cash available.

**Constraints:**
- `2 <= prices.length <= 50`
- `1 <= prices[i] <= 100`
- `1 <= money <= 100`

### Output
Return the leftover money after buying the two cheapest chocolates, or the original amount of money if the purchase cannot be made.

### Examples

**Input:**
```text
prices = [1, 2, 2]
money = 3
```

**Output:**
```text
0
```

---

**Input:**
```text
prices = [3, 2, 3]
money = 3
```

**Output:**
```text
3
```

---
