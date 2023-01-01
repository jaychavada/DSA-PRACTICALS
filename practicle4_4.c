#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

int Traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->val);
        ptr = ptr->next;
    } while (ptr != head);
}

//****************INSERT NODE AT BIGINING*************//
struct node *InsertAtFirst(struct node *head)
{
    int val2;
    printf("Enter a Inert Value : ");
    scanf("%d", &val2);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    do
    {
        head = head->next;
    } while (head->next != head2);
    ptr->val = val2;
    head->next = ptr;
    ptr->prev = head;
    ptr->next = head2;
    head2->prev = ptr;
    head = head2;
    head = ptr;
    return head;
}

//***************INSERT NODE AT END********************//
struct node *InsertAtEnd(struct node *head)
{
    int val2;
    printf("Enter Node Value : ");
    scanf("%d", &val2);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    do
    {
        head = head->next;
    } while (head->next != head2);
    ptr->val = val2;
    head->next = ptr;
    ptr->prev = head;
    ptr->next = head2;
    head2->prev = ptr;
    head = head2;
    return head;
}

// // //****************INSERT AFTER GIVEN VALUE***************//
struct node *InsertAfterGivenValue(struct node *head)
{
    int val2, data;
    printf("Enter a Node Value : ");
    scanf("%d", &val2);
    printf("Enter a Insert Value : ");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    do
    {
        if (head->val == val2)
        {
            break;
        }

        head = head->next;
    } while (head->next != head);
    if (head->val == val2)
    {
        ptr->val = data;
        ptr->next = head->next;
        head->next->prev = ptr;
        head->next = ptr;
        ptr->prev = head;
        head = head2;
        return head;
    }
    else
    {
        printf("Value Not Found");
    }
}
struct node *InsertBeforeGivenValue(struct node *head)
{
    int val2, data;
    printf("Enter a Node Value : ");
    scanf("%d", &val2);
    printf("Enter a Insert Value : ");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *prev1;
    struct node *head2 = head;
    do
    {
        prev1 = head;
        head = head->next;
        if (head->val == val2)
        {
            break;
        }
    } while (head->next != head);
    if (head->val == val2)
    {
        ptr->val = data;
        ptr->next = head;
        head->prev = ptr;
        prev1->next = ptr;
        ptr->prev = prev1;
        head = head2;
        return head;
    }
    else
    {
        printf("Value Not Found ");
    }
}
struct node *DeleteAtFirst(struct node *head)
{
    struct node *ptr = head;
    do
    {
        head = head->next;
    } while (head->next != ptr);
    head->next = ptr->next;
    ptr->next->prev = head;
    free(ptr);

    return head;
}
struct node *DeleteAtEnd(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *prev;
    struct node *head2 = head;
    do
    {
        prev = head;
        head = head->next;
    } while (head->next != head2);
    prev->next = head2;
    head2->prev = head->prev;
    free(head);
    head = head2;
}
struct node *DeleteBeforeGivenNode(struct node *head)
{
    int val2;
    printf("Eter a Node Value : ");
    scanf("%d", &val2);
    struct node *prev1;
    struct node *head2 = head;
    do
    {
        prev1 = head;
        head = head->next;
        if (head->next->val == val2)
        {
            break;
        }
    } while (head->next != head);
    if (head->next->val == val2)
    {
        prev1->next = head->next;
        head->next->prev = prev1;

        free(head);
        head = head2;
        return head;
    }
}
struct node *DeleteAfterGivenNode(struct node *head)
{
    int val2;
    printf("Enter a Node Value : ");
    scanf("%d", &val2);
    struct node *head2 = head;
    struct node *prev1;
    do
    {
        prev1 = head;
        head = head->next;
        if (prev1->val == val2)
        {
            break;
        }
    } while (head->next != head);
    if (prev1->val == val2)
    {

        prev1->next = head->next;
        head->next->prev = prev1;
        free(head);
        head = head2;
        return head;
    }
}
struct node *DeleteSelectiveNode(struct node *head)
{
    int val2;
    printf("Enter a Node Value : ");
    scanf("%d", &val2);
    struct node *prev1;
    struct node *head2 = head;
    do
    {
        prev1 = head;
        head = head->next;
        if (head->val == val2)
        {
            break;
        }
    } while (head->next != head);
    if (head->val == val2)
    {
        prev1->next = head->next;
        head->next->prev = prev1;
        free(head);
        head = head2;
        return head;
    }
    else
    {
        printf("Value Not Found ");
    }
}

void Display(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->val);
        ptr = ptr->next;
    } while (ptr != head);
}


int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->val = 54;
    head->prev = fourth;
    head->next = first;

    first->val = 73;
    first->next = second;
    first->prev = head;

    second->val = 52;
    second->next = third;
    second->prev = first;

    third->val = 34;
    third->next = fourth;
    third->prev = second;

    fourth->val = 24;
    fourth->next = head;
    fourth->prev = third;

    int choice;
 
    printf("\nNAME:JAY CHAVADA\nENROLLMENT NO:210210116006");
    printf("\nMAIN MENU");
    printf("\n\t01 : INSERT AT FIRST");
    printf("\n\t02 : INSERT AT END");
    printf("\n\t03 : INSERT AFTER GIVEN VALUE");
    printf("\n\t04 : INSERT BEFORE GIVEN VALUE");
    printf("\n\t05 : DELETE AT FIRST");
    printf("\n\t06 : DELETE AT END");
    printf("\n\t07 : DELETE BEFORE GIVEN NODE");
    printf("\n\t08 : DELETE AFTER GIVEN NODE");
    printf("\n\t09 : DELETE ANTIRE LIST");
    printf("\n\t10 : DIPLAY");
    printf("\n\t11 : EXIT");
    
    printf("\nENTER YOUR CHOICE : ");
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = InsertAtFirst(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 2:
            InsertAtEnd(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 3:
            InsertAfterGivenValue(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 4:
            InsertBeforeGivenValue(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 5:
            head = DeleteAtFirst(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 6:
            DeleteAtEnd(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 7:
            DeleteBeforeGivenNode(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 8:
            DeleteAfterGivenNode(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 9:
            DeleteSelectiveNode(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 10:
            Display(head);
            printf("\nENTER YOUR NEEDED CHOICE:");
            break;
        case 11:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE");
        }
    }
return 0;
}
