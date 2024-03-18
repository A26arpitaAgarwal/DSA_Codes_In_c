// Implementing insertion sort using c language
#include <stdio.h>
int printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int size)
{
    int key, j;
    for (int i = 1; i <= size - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {23, 56, 8, 53, 98, 12};
    int size = 6;
    printArray(A, size);
    insertionSort(A, size);
    printArray(A, size);
    return 0;
}