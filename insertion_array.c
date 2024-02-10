// Insertion in array
#include <stdio.h>
void display(int arr[], int n)
{
    printf("The array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int insert(int arr[], int a, int size, int index, int capacity)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = a;
    return 1;
}

int main()
{
    int arr[10] = {12, 23, 45, 67};
    int size = 4, a, index, capacity;
    display(arr, size);

    printf("\nEnter the number you wanted to insert: ");
    scanf("%d", &a);
    printf("\nEnter the index at which wanted to insert: ");
    scanf("%d", &index);

    insert(arr, a, size, index, 10);
    size += 1;
    display(arr, size);
    return 0;
}
