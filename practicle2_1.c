#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack
{
    int size;
    int top;
    int *a;
};

int stackFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
int stackEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *s, int value)
{
    if (stackFull(s))
    {
        printf("stack is overflow can not add %d to the stack\n", value);
    }
    else
        s->top++;
    s->a[s->top] = value;
}
int pop(struct stack *s)
{
    if (stackEmpty(s))
    {
        printf("stack is underflow can not pop %d from the stack\n");
    }
    else
        s->top--;
    return s->a[s->top];
}
int peep(struct stack *s)
{
    int i;
    printf("Enter the position\n");
    scanf("%d", &i);

    int place = s->top - i + 1;
    if (place < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
        return s->a[place];
}
int display(struct stack *s)
{
    if (stackEmpty(s))
    {
        printf("Stack is Empty!\n");
    }
    else
        for (int i = s->top; i > -1; i--)
        {
            printf("Elements in stack are : %d \n", s->a[i]);
        }
}
int change(struct stack *s)
{
    int i;
    printf("Enter the position that you want to change \n");
    scanf("%d", &i);
    int element;
    printf("Enter the value you want to change\n");
    scanf("%d", &element);

    int place = s->top - i + 1;
    if (place < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
        return s->a[place] = element;
}
int main()
{
    struct stack s;
    int item;
    int choice;
    int count;
    s.top = -1;
    s.size = 50;
    s.a = (int *)malloc(sizeof(int) * s.size);

    printf("Name : JAY CHAVADA ENROLLMENT NO.:210210116006\n ");

    while (1)
    {
        printf("Main menu \n");
        printf(" 1.push\n 2.pop\n 3.peep\n 4.display\n 5.change\n 6.exit\n");
        printf("Enter the choice you want to perform\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\n Enter how many values to be pushed :");
            scanf("%d", &count);
            for (int i = 1; i <= count; i++)
            {
                printf("enter the %d value : ", i);
                scanf("%d", &item);
                if (stackFull(&s))
                    printf("stack is full");
                else
                    push(&s, item);
            }
            break;

        case 2:
            if (stackEmpty(&s))
                printf("stack is empty \n");
            else
                item = pop(&s);
            break;
        case 3:
            printf("Value is %d\n", peep(&s));
            break;
        case 4:
            display(&s);
            break;
        case 5:
            change(&s);

            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}