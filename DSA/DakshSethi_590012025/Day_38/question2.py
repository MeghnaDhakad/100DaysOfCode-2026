from collections import deque

def cardTrick(n):
    dq = deque()

    for card in range(n, 0, -1):
        if dq:
            dq.appendleft(dq.pop())
        dq.appendleft(card)

    return list(dq)

n = 4
print(cardTrick(n))