#include <stdio.h>

long fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n;
    printf("Enter the number whose factorial you want to find: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d", n, fact(n));
    return 0;
}