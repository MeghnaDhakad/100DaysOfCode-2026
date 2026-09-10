def minimum_coins(coins, amount):
    coins.sort(reverse=True)
    count = 0

    for coin in coins:
        count += amount // coin
        amount %= coin

        if amount == 0:
            break

    return count


n = int(input())
coins = list(map(int, input().split()))
amount = int(input())

print(minimum_coins(coins, amount))