#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int Height(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int BalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return Height(n->left) - Height(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(Height(x->right), Height(x->left)) + 1;
    y->height = max(Height(y->right), Height(y->left)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(Height(x->right), Height(x->left)) + 1;
    y->height = max(Height(y->right), Height(y->left)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return createnode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(Height(node->left), Height(node->right));
    int bf = BalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->key);
        InOrder(root->right);
    }
}

int main()
{
    int n, values;
    struct node *root = NULL;
    printf("\n");
    printf("Name:JAY CHAVADA\nEnrollment no: 210210116006 \n");
    printf("\nHOW MANY ELEMENTS YOU WANT TO INSERT IN AVL TREE :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE NODE VALUE TO INSERT :\n");
        scanf("%d", &values);
        root = insert(root, values);
    }

    printf("\nINORDER TRAVERSAL IS : ");
    InOrder(root);
    return 0;
}
