def toPostfixExp(exp):
    tokens = exp.split()
    stack = []
    operators = {
        '^': 3, 
        '/': 2, 
        '*': 2, 
        '+': 1, 
        '-': 1
        }
    outputList = []


    for token in tokens:
        if token.isalnum():  #".isalnum()" checks whether the string has alphabets (like a, b...z) or numerical values (like 1, 2, ..)
            outputList.append(token)

        elif token in operators:
            while len(stack) > 0 and stack[-1] != '(':  # Here, "stack[-1]" means negative indexing. Checks the (length-1) index position of the list
                if operators[token] <= operators[stack[-1]]:  # Acessing dictionary values using keys
                    outputList.append(stack.pop())  # Appending to the output while removing from the stack
                else: 
                    break
            stack.append(token)

        elif token == '(':
            stack.append(token)

        elif token == ')':
            while len(stack) > 0 and stack[-1] != '(':
                outputList.append(stack.pop())  # Popping every operators that comes within
            if len(stack) > 0:
                stack.pop()  # Removing the remaining parenthesis as it is not removed in the above while loop


    while len(stack) > 0:
        outputList.append(stack.pop())  # Popping out every remaining operator from the stack and adding it to the output

    return ' '.join(outputList)  # Joins the elements of the list by separating with the space ' '



exp = input("Enter the expression: ")
ans = toPostfixExp(exp)
print(f"The equivalent postfix expression is: {ans}")