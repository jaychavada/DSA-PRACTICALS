#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;

    fptr = fopen("double.txt", "w");

    char **name;

    name = (char **)malloc(25);

    for (int i = 0; i < 5; i++)
    {
        name[i] = (char *)malloc(25);
    }

    printf("Name : JAY CHAVADA ENROLLMENT NO.:210210116006\n ");
    printf("ENTER THE NAME OF CITY \n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%s", name[i]);
    }

    printf("------------------------\n ");

    char temp[25];

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {

                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(fptr, "%s\n", name[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", name[i]);
    }

    return 0;
}