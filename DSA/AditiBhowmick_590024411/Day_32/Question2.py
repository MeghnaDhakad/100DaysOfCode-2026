stack = list(map(int, input("Enter stack elements: ").split()))
temp = []
copied = []

# Move elements from original stack to temporary stack
while stack:
    temp.append(stack.pop())

# Restore original stack and create copied stack
while temp:
    x = temp.pop()
    stack.append(x)
    copied.append(x)

print("Copied Stack:", copied)