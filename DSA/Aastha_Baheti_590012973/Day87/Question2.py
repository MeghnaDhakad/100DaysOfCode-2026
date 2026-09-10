def min_coins(coins, amount):
    coins.sort(reverse=True)
    count = 0

    for coin in coins:
        count += amount // coin
        amount %= coin

    return count if amount == 0 else -1


n = int(input())
coins = list(map(int, input().split()))
amount = int(input())

print(min_coins(coins, amount))