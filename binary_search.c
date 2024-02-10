// binary search of element
// The array must be sorted before

#include <stdio.h>
int binarySearch(int arr[], int element, int size)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {2, 3, 5, 34, 67, 98, 132, 223};
    int element = 223;
    int size = sizeof(arr) / sizeof(int);
    int index = binarySearch(arr, element, size);
    printf("The element %d has been found at index %d.", element, index);
    return 0;
}