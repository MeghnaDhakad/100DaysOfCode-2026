n = int(input("Enter the number of cards: "))
deck = []

for i in range(n, 0, -1):
    if deck:
        deck.insert(0, deck.pop())
    deck.insert(0, i)

print("Final arrangement of cards:")
print(*deck)
