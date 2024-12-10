def postfixEvaluation(exp):
    operators = ('^', '/', '*', '+', '-')
    stack = []
    tokens = exp.split()

    for token in tokens:
        if token in operators:
            op1 = stack.pop()
            op2 = stack.pop()
            if token == '^':
                result = op2 ** op1
            elif token == '/':
                result = op2 / op1
            elif token == '*':
                result = op2 * op1
            elif token == '+':
                result = op2 + op1
            elif token == '-':
                result = op2 - op1
            stack.append(result)
        else:
            stack.append(float(token))

    return stack[0]

exp = input("Enter the expression: ")
ans = postfixEvaluation(exp)
print(f"The result is {ans}")