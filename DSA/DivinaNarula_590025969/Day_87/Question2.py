# Minimum Number of Coins

coins = list(map(int, input("Enter coin denominations: ").split()))
amount = int(input("Enter the target amount: "))

coins.sort(reverse=True)

count = 0
remaining = amount

for coin in coins:
    if coin <= remaining:
        used = remaining // coin
        count += used
        remaining %= coin

    if remaining == 0:
        break

if remaining == 0:
    print("Minimum number of coins:", count)
else:
    print("Amount cannot be formed with the given coins")