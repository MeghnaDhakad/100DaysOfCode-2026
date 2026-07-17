def postfixToPrefix(s):
    stack = []

    operators = {'+', '-', '*', '/'}

    for ch in s:
        if ch not in operators:
            stack.append(ch)
        else:
            op2 = stack.pop()
            op1 = stack.pop()

            temp = ch + op1 + op2
            stack.append(temp)

    return stack[-1]


# Input
s = input()
print(postfixToPrefix(s))