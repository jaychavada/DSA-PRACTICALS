// Prim’s Algorithm:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define INF 9999999
#define V 5
int G[V][V] = {
    {0, 9, 7, 0, 0},
    {9, 0, 8, 1, 4},
    {7, 8, 0, 5, 6},
    {0, 1, 5, 0, 3},
    {0, 4, 6, 3, 0}};
int main()
{
    printf("\nName:JAY CHAVADA\nEnrollment no: 210210116006\n \n");
    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;
    printf("Edge : Weight\n");
    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }
    return 0;
}