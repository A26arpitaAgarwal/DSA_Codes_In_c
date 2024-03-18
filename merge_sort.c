// Implementing merge sort using c language
#include <stdio.h>
int printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void mergeSort(int A[], int low, int mid, int high)
{
    int i, j, k, B[10];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void recursiveMS(int X[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        recursiveMS(X, low, mid);
        recursiveMS(X, mid + 1, high);
        mergeSort(X, low, mid, high);
    }
}

int main()
{
    int A[] = {23, 4, 679, 80, 19, 32, 2};
    int size = 7;
    printArray(A, size);
    recursiveMS(A, 0, 6);
    printArray(A, size);
    return 0;
}