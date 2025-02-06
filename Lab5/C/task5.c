#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int l, int r)
{
    int X = l, Y = r, pivot = A[l], temp;
    while ((X < Y))
    {
        while (A[X] <= pivot && X <= r)
            X++;
        while (A[Y] > pivot && Y > l)
            Y--;
        if (X < Y)
        {
            temp = A[X];
            A[X] = A[Y];
            A[Y] = temp;
        }
    }
    temp = A[l];
    A[l] = A[Y];
    A[Y] = temp;
    return Y;
}

void quickSort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);
    }
}

void displaY(int A[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[100000], n, i;
    clock_t start, end, diff;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    // displaY(A, n);
    start = clock();
    quickSort(A, 0, n - 1);
    end = clock();
    // displaY(A, n);
    diff = end - start;
    printf("Time taken is %f seconds \n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}

// Time taken = 0.028s for 100000 entries