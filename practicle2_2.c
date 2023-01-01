#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{

    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *sp)
{

    if (sp->top == sp->size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow! Cannot pop from the stack\n");
    }
    else
    {
        ptr->top--;
        return ptr->arr[ptr->top];
    }
}
int main()
{
    char str[30];
    struct stack sp;

    sp.top = -1;
    sp.size = 10;
    sp.arr = (int *)malloc(sizeof(int) * 5);

    printf("Name: Jay chavada Enrollment no.: 210210116006\n");
    printf("Enter the String You want to reverse \n");
    scanf("%s", str);

    for (int i = 0; i <= strlen(str); i++)
    {
        push(&sp, str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop(&sp);
    }

    printf("%s", str);

    return 0;
}