stack = list(map(int, input("Enter stack elements: ").split()))

temp = []
copy_stack = []

while stack:
    temp.append(stack.pop())

while temp:
    x = temp.pop()
    stack.append(x)
    copy_stack.append(x)

print(copy_stack)