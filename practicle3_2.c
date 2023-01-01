#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int front;
    int rear;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->rear = (q->rear +1 )%q->size;
        q->arr[q->rear] = val; 
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->front = (q->front +1)%q->size;
        a = q->arr[q->front]; 
    }
    return a;
}
void display(struct circularQueue *q)
{
    printf("Elements of the queue are..\n");

    if (q->rear == q->front)
    {
        printf("This Queue is empty\n");
    }
    else
    {
        for (int i = q->rear; i > q->front; i--)
        {
            printf("%d\t", q->arr[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct circularQueue q;

    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int ch;
    int element;

    while (1)
    {
        printf("\n");
        printf("NAME : Jay Chavada ENROLLMENT NO. : 210210116006\n");
        printf("\n");

        printf("1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT\n");

        printf("ENTER YOUR CHOICE \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("ENTER THE ELEMENT for ENQUEUE \n");
            scanf("%d", &element);
            enqueue(&q, element);
            system("cls");
            break;

        case 2:
            dequeue(&q);
            system("cls");
            break;

        case 3:
            system("cls");
            display(&q);
            break;

        case 4:
            exit(1);

        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}