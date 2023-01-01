#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

struct linkedlist *insertatfirst(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    ptr->next = first;
    ptr->data = val;
    return ptr;
}

struct linkedlist *insertatEnd(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    ptr->data = val;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return first;
}

struct linkedlist *insertAfterNode(struct linkedlist *first, struct linkedlist *beforeNode, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    ptr->data = val;
    ptr->next = beforeNode->next;
    beforeNode->next = ptr;
    return first;
}

struct linkedlist *insertBeforeNode(struct linkedlist *first, struct linkedlist *AfterNode, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    while (p->next != AfterNode)
    {
        p = p->next;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

struct linkedlist *delationatfirst(struct linkedlist *first)
{
    struct linkedlist *ptr = first;
    first = first->next;
    free(ptr);

    return first;
}

struct linkedlist *delationatEnd(struct linkedlist *first)
{
    struct linkedlist *p = first;
    struct linkedlist *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return first;
}

struct linkedlist *delationatNode(struct linkedlist *first, int val)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    while (q->data != val)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("VALUE IS NOT AVAILABLE\n");
    }

    return first;
}

struct linkedlist *delationBeforeNode(struct linkedlist *first, struct linkedlist *AfterNode)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    while (q->next != AfterNode)
    {
        p = p->next;
        q = q->next;
    }
    p->next = AfterNode;
    free(q);
    return first;
}

struct linkedlist *delationAfterNode(struct linkedlist *first, struct linkedlist *BeforeNode)
{
    struct linkedlist *p = first->next;
    struct linkedlist *q = first;

    while (p->next != BeforeNode->next)
    {
        p = p->next;
        q = q->next;
    }
    BeforeNode->next = p;
    free(q);

    return first;
}
struct linkedlist *deleteEntireLinkedlist(struct linkedlist *first){
    struct linkedlist *head2;
    struct linkedlist *temp;
    head2 = first;

    while (head2 != NULL)
    {
        temp = head2->next;
        free(head2);
        head2 = temp;
    }
        first = head2;
}

void display(struct linkedlist *ptr)
{

    printf("\t ENTERED LINKEDLIST IS-----\n");

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()

{

    int index;
    int value;
    int ch;
    int element;

    struct linkedlist *first;
    struct linkedlist *second;
    struct linkedlist *third;
    struct linkedlist *fourth;
    struct linkedlist *fifth;

    first = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    second = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    third = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fourth = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fifth = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    printf("\n");
    printf("NAME : JAY CHAVADA  ENROLLMENT NO. : 210210116006   \n");
    printf("\n");

    printf("1.  INSERT THE ELEMENT AT BEGINING \n");
    printf("2.  INSERT THE ELEMENT AT THE END \n");
    printf("3.  INSERT AFTER A NODE \n");
    printf("4.  INSERT BEFORE A NODE \n");
    printf("5.  DELATION AT BEGINING \n");
    printf("6.  DELATION AT END \n");
    printf("7.  DELATION AT index \n");
    printf("8.  DELATION BEFORE NODE \n");
    printf("9.  DELATION AFTER NODE \n");
    printf("10. DELETE THE ENTIRE LIST \n");
    printf("11. DISPLAY \n");
    printf("12. EXIT \n \n");

    while (1)
    {
        printf("ENTER YOUR CHOICE THAT YOU WANT TO PERFORM :");
        scanf("%d", &ch);

        switch (ch)

        {
        case 1:
            printf("ENTER THE ELEMENT THAT YOU WANT TO INSERT :");
            scanf("%d", &element);
            first = insertatfirst(first, element);
            break;

        case 2:

            printf("ENTER THE ELEMENT THAT YOU WANT TO INSERT :");
            scanf("%d", &element);
            first = insertatEnd(first, element);
            break;

        case 3:
            printf("ENTER THE ELEMENT THAT YOU WANT TO INSERT AFTER NODE :");
            scanf("%d", &element);
            first = insertAfterNode(first, second, element);
            break;

        case 4:
            printf("ENTER THE ELEMENT THAT YOU WANT TO INSERT BEFORE NODE :");
            scanf("%d", &element);
            first = insertBeforeNode(first, second, element);
            break;

        case 5:
            delationatfirst(first);
            break;

        case 6:
            delationatEnd(first);
            break;

        case 7:
            printf("ENTER THE index AT THAT YOU WANT TO DELATION :");
            scanf("%d", index);
            delationatNode(first, index);
            break;

        case 8:
            delationBeforeNode(first, second);
            break;

        case 9:
            delationAfterNode(first, second);
            break;
        case 10:
            first = deleteEntireLinkedlist(first);
            printf("\t ----Linkedlist is deleted--- \n");
        case 11:
            display(first);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            break;

        case 12:
            exit(0);

        default:
            printf("INVALID INSERTION \n");
        }
    }

    return 0;
}