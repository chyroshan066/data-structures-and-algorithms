#include <stdio.h>
#define MAX 100

int table[MAX] = {0}; // Initializes to 0

int fiboM(int n)
{
    int arr[100];
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0) // If table[n] = 0 that means the value is not in the table
            table[n] = fiboM(n - 1) + fiboM(n - 2);
        return table[n];
    }
}

int main()
{
    int n;
    printf("Enter the fibonacci term you want to find: ");
    scanf("%d", &n);
    int ans = fiboM(n);
    if (n == 1)
        printf("The %dst fibonacci term is %d", n, ans);
    else if (n == 2)
        printf("The %dnd fibonacci term is %d", n, ans);
    else if (n == 3)
        printf("The %drd fibonacci term is %d", n, ans);
    else
        printf("The %dth fibonacci term is %d", n, ans);
    return 0;
}