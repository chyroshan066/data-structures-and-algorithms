#include <stdio.h>

void TOH(int n, char src, char tmp, char dst)
{
    if (n <= 0)
        printf("Invalid entry\n");
    else if (n == 1)
        printf("Move disc %d from %c to %c\n", n, src, dst);
    else
    {
        TOH(n - 1, src, tmp, dst);
        printf("Move disc %d from %c to %c\n", n, src, dst);
        TOH(n - 1, tmp, dst, src);
    }
}

int main()
{
    int n;
    char src = 'A', tmp = 'B', dst = 'C';
    printf("Enter the number of disc: ");
    scanf("%d", &n);
    printf("Tower of Hanoi of %d disc:\n", n);
    TOH(n, src, tmp, dst);
    return 0;
}