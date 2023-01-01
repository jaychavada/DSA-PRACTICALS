#include <stdio.h>
#include <conio.h>
#include <string.h>
#define size 100
char postfix[size];
int stack[size];
int top = -1;
int push(char a)
{
    if (top > size)
    {
        printf("\nStack full..");
        return 0;
    }
    else
    {
        top++;
        stack[top] = a;
    }
    return 0;
}
int pop()
{
    int a;
    if (top == -1)
    {
        printf("\nStack Empty..");
        return 0;
    }
    else
    {
        a = stack[top];
        top--;
        return a;
    }
}
void evaluate(char postfix[size])
{
    int i = 0, x, y, num, value = 0, val;
    char item;
    item = postfix[i];
    while (item != '\0')
    {
        if (item == '+' || item == '-' || item == '*' || item == '/')
        {
            x = pop();
            y = pop();
            switch (item)
            {
            case '+':
                value = y + x;
                break;
            case '-':
                value = y - x;
                break;
            case '*':
                value = y * x;
                break;
            case '/':
                value = y / x;
                break;
            }
            push(value);
        }
        else
        {
            num = item - 48;
            push(num);
        }
        i++;
        item = postfix[i];
    }
    val = pop();
    printf("%d ", val);
}
int main()
{
    printf("\n");
    printf("NAME : JAY CHAVADA  ENROLLMENT NO. : 210210116006   \n");
    printf("\n");
    printf("\n Enter the Postfix Expression : ");
    gets(postfix);
    evaluate(postfix);
    return 0;
}