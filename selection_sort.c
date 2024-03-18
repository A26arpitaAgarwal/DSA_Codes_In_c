// Implementing selection sort using c language
#include <stdio.h>
int printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int size)
{
    int min, i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        min = A[i];
        k = i;
        for (j = i + 1; j < size; j++)
        {
            if ((A[j] < min))
            {
                min = A[j];
                k = j;
            }
        }
        A[k] = A[i];
        A[i] = min;
    }
}

int main()
{
    int A[] = {13, 5, 5, 30, 22, 16, 8};
    int size = 7;
    printArray(A, size);
    selectionSort(A, size);
    printArray(A, size);
    return 0;
}