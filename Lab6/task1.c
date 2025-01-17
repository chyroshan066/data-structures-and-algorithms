#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void maxHeapify(int A[], int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    int temp;

    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (i != largest)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, n);
    }
}

void buildMaxHeap(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(A, i, n);
}

void HeapSort(int A[], int n)
{
    buildMaxHeap(A, n);
    int temp;
    for (int i = n - 1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A, 0, i);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[100000], n, i;
    clock_t start, end;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand() % 10000;
    // display(A, n);
    start = clock();
    HeapSort(A, n);
    end = clock();
    // display(A, n);
    printf("Time taken is %f seconds \n", (float)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

// Time taken = 0.026s for 100000 entries