// Bubble sort
#include <stdio.h>
#include <conio.h>
void main()
{
    printf("\n");
    printf("Name: JAY CHAVADA \nEnrollment no: 210210116006 \n\n");
    int array[100], n, c, d, swap;
    printf("Number of Elements to Add:");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf("%d ", array[c]);
}
