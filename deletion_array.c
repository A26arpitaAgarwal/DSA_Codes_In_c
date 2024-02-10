// Deletion in array
#include <stdio.h>
void display(int arr[], int n)
{
    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int delete(int arr[], int a, int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[10] = {12, 23, 45, 67};
    int size = 4, a, index, capacity;
    display(arr, size);

    printf("\nEnter the number you wanted to delete: ");
    scanf("%d", &a);
    printf("\nEnter the index at which wanted to insert: ");
    scanf("%d", &index);

    delete (arr, a, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}
