#include <stdio.h>
int binarySearch(int A[], int l, int r, int key)
{
    int m;
    do
    {
        m = (l + r) / 2;
        if (key == A[m])
        {
            printf("Search successful!!!!!");
            return m;
        }
        else if (key < A[m])
            r = m - 1;
        else
            l = m + 1;
    } while (l <= r);
    return -1;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    binarySearch(A, 0, n - 1, key);
    return 0;
}