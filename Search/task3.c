#include <stdio.h>
int linearSearch(int A[], int n, int key)
{
    int flag = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            printf("Search found!!!!!");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Search unsuccessful!!!!");
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
    linearSearch(A, n, key);
    return 0;
}