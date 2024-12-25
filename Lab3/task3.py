def fiboM(n):
    table = {}
    if n == 1 or n == 2:
        return 1
    else:
        if n not in table:
            result = fiboM(n-1) + fiboM(n-2)
            table[n] = result
        return table[n]
    

n = int(input("Enter the fibonacci term you want to find: "))
ans = fiboM(n)
if n == 1:
    print(f"The {n}st fibonacci term is {ans}")
elif n == 2:
    print(f"The {n}nd fibonacci term is {ans}")
elif n == 3:
    print(f"The {n}rd fibonacci term is {ans}")
else:
    print(f"The {n}st fibonacci term is {ans}")