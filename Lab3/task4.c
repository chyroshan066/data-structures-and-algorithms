#include <stdio.h>

int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    printf("Enter the fibonacci term you want to find: ");
    scanf("%d", &n);
    if (n == 1)
        printf("The %dst fibonacci term is %d", n, fibo(n));
    else if (n == 2)
        printf("The %dnd fibonacci term is %d", n, fibo(n));
    else if (n == 3)
        printf("The %drd fibonacci term is %d", n, fibo(n));
    else
        printf("The %dth fibonacci term is %d", n, fibo(n));
    return 0;
}