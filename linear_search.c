// linear search of element
// It is not mandatory that the array should be sorted

#include <stdio.h>
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int main()
{
    int arr[10] = {12, 3, 7, 45, 23};
    int element = 12;
    int size = sizeof(arr) / sizeof(int);

    int index = linearSearch(arr, size, element);
    printf("The element %d has been found at index: %d\n", element, index);
    return 0;
}