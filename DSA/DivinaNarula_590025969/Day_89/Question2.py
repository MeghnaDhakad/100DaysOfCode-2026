# Buy Two Chocolates

def buy_two_chocolates(prices, money):
    first = float('inf')
    second = float('inf')

    for price in prices:
        if price < first:
            second = first
            first = price
        elif price < second:
            second = price

    total = first + second

    if total <= money:
        return money - total

    return money


prices = list(map(int, input("Enter Prices: ").split()))
money = int(input("Enter Money: "))

print(buy_two_chocolates(prices, money))