// Implementing bubble sort algorithm using c language
#include <stdio.h>

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int size)
{
    // For number of passes
    for (int i = 0; i < size - 1; i++)
    {
        // Possible comparison and swaps in one pass
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {12, 5, 65, 1, 32};
    int size = 5;
    printArray(A, size);
    bubbleSort(A, size);
    printArray(A, size);
    return 0;
}