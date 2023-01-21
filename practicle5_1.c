#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// NODE CREATION
struct node *createnode(int data)
{
    struct node *n;                                 // creating node pointer
    n = (struct node *)malloc(sizeof(struct node)); // memory allocation
    n->data = data;                                 // set data
    n->left = NULL;
    n->right = NULL;
    return n;
}
// SEARCHING
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}
// INSERTION
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("KEY CAN'T BE INSERT\n");
            break;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    struct node *new1 = createnode(key);
    if (key < prev->data)
    {
        prev->left = new1;
    }
    else
    {
        prev->right = new1;
    }
    printf("NODE HAS BEEN INSERTED\n");
}
// FOR DELETION
struct node *InOrderPredecessor(struct node *root)
{ // it is a left sub tree's right most child
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
// DELETION
struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;

    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // search for node wants to be delete
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy
    else
    {
        iPre = InOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
// TRAVARSAL IN TREE
void preOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTravarsal(root->left);
        preOrderTravarsal(root->right);
    }
}
void postOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTravarsal(root->left);
        postOrderTravarsal(root->right);
        printf("%d ", root->data);
    }
}
void InOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTravarsal(root->left);
        printf("%d ", root->data);
        InOrderTravarsal(root->right);
    }
}
int countNODE(struct node *root)
{
    static int count = 0;
    if (root != NULL)
    {
        countNODE(root->left);
        count++;
        countNODE(root->right);
    }
    return count;
}

int leafNODE(struct node *root)
{
    static int leaf = 0;
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            leaf++;
        }
        leafNODE(root->left);
        leafNODE(root->right);
        return leaf;
    }
}
int height(struct node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int i, j;
    i = height(root->left);
    j = height(root->right);
    if (i > j)
    {
        return i + 1;
    }
    else
        return j + 1;
}
void _deleteTree(struct node* node)
{
       if (node->left)
       {
             _deleteTree(node->left);
             free(node->left);
       }
       if (node->right)
       {
             _deleteTree(node->right);
             free(node->right);
       }
}

void deleteTree(struct node** node_ref)
{
     if (*node_ref)
     {
          _deleteTree(*node_ref);
          free(*node_ref);
     }
}

int main()
{
    printf("Name:JAY CHAVADA Enrollment no: 210210116006 \n");
    printf("\n------- Binary Search Tree ------\n");
    printf("\n 1.INSERT A NODE\n 2.SEARCH A NODE\n");
    printf("\n 3.TRAVARSALS(INORDER,PREORDER,POSTORDER)\n 4.DELETE A NODE IN TREE\n ");
    printf("\n 5.HEIGHT OF TREE\n 6.TOTAL NO. OF NODES,INTERNAL NODES,LEAF NODES\n 7.exit\n\n");

    struct node *p = createnode(50);
    struct node *p1 = createnode(30);
    struct node *p2 = createnode(60);
    struct node *p3 = createnode(10);
    struct node *p4 = createnode(40);
    struct node *p5 = createnode(42);
    struct node *p6 = createnode(35);
    struct node *p7 = createnode(70);
    struct node *p8 = createnode(58);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->right = p5;
    p4->left = p6;
    p2->right = p7;
    p2->left = p8;

    /*       50
            /  \
           /    \
         30     60
        /\     / \
       /  \   58 70
      10  40
          / \
         35  42
   */
    int ch, n;
    int TOTAL = countNODE(p);
    int LEAF = leafNODE(p);
    while (1)
    {
        printf("ENTER THE CHOICE YOU WANT TO PERFORM : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nENTER THE NODE VALUE YOU WANT TO INSERT : ");
            scanf("%d", &n);
            insert(p, n);
            break;
        case 2:
            printf("\nENTER THE NODE VALUE YOU WANT TO SEARCH : ");
            scanf("%d", &n);
            search(p, n);
            struct node *temp = search(p, n);
            if (temp != NULL)
            {
                printf("Found :  %d", temp->data);
            }
            else
            {
                printf("Node not found");
            }
            printf("\n");
            break;
        case 3:
            printf("\nINORDER TRAVERSAL IS : ");
            InOrderTravarsal(p);
            printf("\n\nPREORDER TRAVERSAL IS : ");
            preOrderTravarsal(p);
            printf("\n\nPOSTORDER TRAVERSAL IS: ");
            postOrderTravarsal(p);
            printf("\n");
            break;

        case 4:
            printf("\n ENTER THE NUMBER YOU WANT TO DELETE :");
            scanf("%d", &n);
            deleteNode(p, n);
            break;
    
        case 5:
            printf("HEIGHT of TREE is %d\n", height(p1));
            break;

        case 6:
            printf("\n TOTAL NO. OF NODES ARE %d ", TOTAL);
            printf("\n TOTAL NO. OF LEAF NODES ARE %d ", LEAF);
            printf("\n TOTAL NO. OF INTERNAL NODES ARE %d ", TOTAL - LEAF);
        case 7:
            exit(1);

        default:
            printf("\n\tInvalid Choice\n");
            break;
        }
    }
    return 0;
}