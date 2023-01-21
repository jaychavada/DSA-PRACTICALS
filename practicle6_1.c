#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
struct Vertex *lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

struct Vertex
{
   char lab;
   bool visited;
};
void insert(int data)
{
   queue[++rear] = data;
   queueItemCount++;
}

int removeData()
{
   queueItemCount--;
   return queue[front++];
}

bool isQueueEmpty()
{
   return queueItemCount == 0;
}
void addVertex(char lab)
{
   struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
   vertex->lab = lab;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}
void addEdge(int start, int end)
{
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex)
{
   printf("%c ", lstVertices[vertexIndex]->lab);
}
int getAdjUnvisitedVertex(int vertexIndex)
{
   int i;

   for (i = 0; i < vertexCount; i++)
   {
      if (adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }
   return -1;
}

void breadthFirstSearch()
{
   int i;
   lstVertices[0]->visited = true;
   displayVertex(0);
   insert(0);
   int unvisitedVertex;

   while (!isQueueEmpty())
   {
      int tempVertex = removeData();
      while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
      {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);
      }
   }
   for (i = 0; i < vertexCount; i++)
   {
      lstVertices[i]->visited = false;
   }
}

int main()
{
   int i, j, a;

   for (i = 0; i < MAX; i++)
      for (j = 0; j < MAX; j++)
         adjMatrix[i][j] = 0;

   printf("\n");
   printf("Name: JAY CHAVADA \nEnrollment no: 210210116006 \n");

   printf("\nEnter any 5 element that you want to add in graph : \n");
   for (int p = 0; p < 5; p++)
   {
      scanf("%c", &a);
      addVertex(a);
   }

   addEdge(0, 1);
   addEdge(0, 2);
   addEdge(0, 3);
   addEdge(1, 4);
   addEdge(2, 4);
   addEdge(3, 4);

   printf("\nBreadth First Search: ");

   breadthFirstSearch();

   return 0;
}
