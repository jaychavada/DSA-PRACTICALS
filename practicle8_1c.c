//-Insertion short:
#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    printf("\n");
    printf("Name: JAY CHAVADA\nEnrollment no: 210210116006 \n");
    int array[10], n, c;
    printf("Numbers of Elements to Add:");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    insertionSort(array, n);
    printf("Sorted array: \n");
    printArray(array, n);
    return 0;
}
