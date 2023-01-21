// - Binary search
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(void)
{
    printf("\n");
    printf("Name:JAY CHAVADA \nEnrollment no: 210210116006\n \n");
    int arr[] = {24, 44, 45, 12, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 44;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element %d is present at index %d", x, result);
    return 0;
}
