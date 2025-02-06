#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n)
{
    int i, j, temp, least, pos;
    for (i = 0; i < n; i++)
    {
        least = A[i];
        pos = i;
        for (j = 0; j < n; j++)
            if (A[j] < least)
                least = A[j];
        pos = j;
        if (i != pos)
        {
            temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
    }
}

void display(int A[], int n)
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
    // display(A, n);
    start = clock();
    selectionSort(A, n);
    end = clock();
    // display(A, n);
    diff = end - start;
    printf("Time taken is %f seconds \n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}

// Time taken = 26s for 100000 entries