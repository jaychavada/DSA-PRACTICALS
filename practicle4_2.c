#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

int Traversal(struct node *ptr)
{

    while (ptr != NULL)
    {   int i =1;
        printf("Element %d is : %d\n", ptr->val);
        ptr = ptr->next;
        i++;
    }
}

//****************INSERT NODE AT BIGINING*************//
struct node *InsertAtFirst(struct node *head)
{
    int val2;
    printf("Enter Node Value\n");
    scanf("%d", &val2);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = val2;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev=NULL;
    head = ptr;
    return head;
}

//***************INSERT NODE AT END********************//
struct node *InsertAtEnd(struct node *head)
{
    int val2;
    printf("Enter Node Value\n");
    scanf("%d", &val2);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    ptr->val = val2;
    head->next = ptr;
    ptr->prev = head;
    ptr->next = NULL;
    head = head2;
    return head;
}

//****************INSERT AFTER GIVEN VALUE***************//
struct node *InsertAfterGivenValue(struct node *head)
{
    int val2, data;
    printf("Enter a Node Value");
    scanf("%d", &val2);
    printf("Enter a Insert Value");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = head;
    while (head->val!=NULL)
    {
        if (head->val == val2)
        {
            break;
        }

        head = head->next;
    }
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
    printf("Enter a Node Value");
    scanf("%d", &val2);
    printf("Enter a Insert Value");
    scanf("%d", &data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *prev1;
    struct node *head2 = head;
    while (head->val != val2)
    {
        prev1 = head;
       
        head = head->next;
    }
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
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}
struct node *DeleteAtEnd(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *prev;
    struct node *head2 = head;
    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
    }
    if (head->next == NULL)
    {
        prev->next = NULL;
        head->prev = NULL;
        free(head);
        head = head2;
    }
}
struct node *DeleteBeforeGivenNode(struct node *head)
{
    int val2;
    printf("Enter a Node Value");
    scanf("%d", &val2);
    struct node *prev1;
    struct node *head2 = head;
    while (head->next->val != val2)
    {
        prev1 = head;
        head = head->next;
    }
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
    printf("Enter a Node Value");
    scanf("%d", &val2);
    struct node *head2 = head;
    struct node *prev1;
    while (prev1->val != val2)
    {
        prev1 = head;
        head = head->next;
    }
    if (prev1->val == val2)
    {

        prev1->next = head->next;
        head->next->prev = prev1;
        free(head);
        head = head2;
        return head;
    }
}
struct node *DeleteEntireList(struct node *head)
{
    int val2;
    printf("Enter a Node Value");
    scanf("%d", &val2);
    struct node *prev1;
    struct node *head2 = head;
    while (head->val != val2)
    {
        prev1 = head;
        
        head = head->next;
    }
    if (head->val == val2)
    {
        prev1->next = head->next;
        head->next->prev=prev1;
       
        free(head);
        head = head2;
        return head;
    }
    
}
void Display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->val);
        ptr = ptr->next;
    }
}
void search()
{
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
    head->prev = NULL;
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
    fourth->next = NULL;
    fourth->prev = third;

    int choice;
    
    printf("\nNAME:JAY CHAVADA ENROLLMENT NO:210210116006\n");
    
    printf("\n\nMAIN MENU\n");
   
    printf("\n\t01 : INSERT AT FIRST");
    printf("\n\t02 : INSERT AT END");
    printf("\n\t03 : INSERT AFTER GIVEN VALUE");
    printf("\n\t04 : INSERT BEFORE GIVEN VALUE");
    printf("\n\t05 : DELETE AT FIRST");
    printf("\n\t06 : DELETE AT END");
    printf("\n\t07 : DELETE BEFORE GIVEN NODE");
    printf("\n\t08 : DELETE AFTER GIVEN NODE");
    printf("\n\t09 : DELETE ANTIRE LIST");
    printf("\n\t10 : SEARCH GIVEN NODE");
    printf("\n\t11 : DIPLAY");
    printf("\n\t12 : EXIT");
   
    printf("\n\nENTER YOUR CHOICE:");
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head=InsertAtFirst(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 2:
            InsertAtEnd(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 3:
            InsertAfterGivenValue(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 4:
            InsertBeforeGivenValue(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 5:
            head=DeleteAtFirst(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 6:
            DeleteAtEnd(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 7:
            DeleteBeforeGivenNode(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 8:
            DeleteAfterGivenNode(head);
             printf("\nENTER YOUR CHOICE:");
            break;
        case 9:
            DeleteEntireList(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 10:
            search();
            printf("\nENTER YOUR CHOICE:");
            break;
        case 11:
            Display(head);
            printf("\nENTER YOUR CHOICE:");
            break;
        case 12:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE");
        }
    }

    return 0;
}
