// - Linear search:
#include <stdio.h>
int linearSearch(int a[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val)
            return i + 1;
    }
    return -1;
}
int main()
{
    printf("\n");
    printf("Name: JAY CHAVADA \nEnrollment no: 210210116006\n \n");
    int a[10], n, c, val;
    printf("number of elements to add:");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
    {
        scanf("%d", &a[c]);
    }
    printf("Enter value to be searched : ");
    scanf("%d", &val);
    int res = linearSearch(a, n, val);
    printf("The elements of the array are : ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nElement to be searched is %d", val);
    if (res == -1)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at %d position of array", res);
    return 0;
}