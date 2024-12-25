#include <stdio.h>

int recursiveGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return recursiveGCD(b, a % b);
};

int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("The GCD of %d and %d is %d", num1, num2, recursiveGCD(num1, num2));
    return 0;
}