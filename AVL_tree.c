#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
    int height;
};
struct node *getnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->height = 1;
    return newnode;
}
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}
int balancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(n->left) - getheight(n->right);
    }
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getheight(y->right), getheight(y->left));
    x->height = max(getheight(x->right), getheight(x->left));

    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getheight(y->right), getheight(y->left));
    x->height = max(getheight(x->right), getheight(x->left));

    return y;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
struct node *insert(struct node *newnode, int data)
{
    if (newnode == NULL)
    {
        return getnode(data);
    }  
    if (data < newnode->data)
    {
        newnode->left = insert(newnode->left, data);
    }
    else if (data > newnode->data)
    {
        newnode->right = insert(newnode->right, data);
    }
    return newnode;
    newnode->height = 1 + max(getheight(newnode->left), getheight(newnode->right));
    int bf = balancefactor(newnode);

    // left left
    if (bf > 1 && data < newnode->left->data)
    {
        return rightrotate(newnode);
    }
    // right right
    if (bf < -1 && data > newnode->right->data)
    {
        return leftrotate(newnode);
    }
    // left right
    if (bf > 1 && data > newnode->left->data)
    {
        newnode->left = leftrotate(newnode->left);
        rightrotate(newnode);
    }
    // right left
    if (bf < -1 && data < newnode->right->data)
    {
        newnode->right = rightrotate(newnode->right);
        leftrotate(newnode);
    }
}
void printRandoms(int lower, int upper, int count, FILE *ptr)
{
    int i;
    printf("Enter count\n");
    scanf("%d", &count);
    printf("Enter lower\n");
    scanf("%d", &lower);
    printf("Enter upper\n");
    scanf("%d", &upper);
    for (i = 0; i < count; i++)
    {
        int num = (rand() %
                   (upper - lower + 1)) +
                  lower;
        printf("%d ", num);
        fprintf(ptr, "%d\n", num);
    }
    fclose(ptr);
}
void inorder(struct node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        printf("%d\t", n->data);
        inorder(n->right);
    }
}

int main()
{
    FILE *ptr;
    struct node *root = NULL;
    int lower, data, upper, count, val, n;
    ptr = fopen("AVL_input.txt", "w");
    printRandoms(lower, upper, count, ptr);
    ptr = fopen("AVL_input.txt", "r");
    printf("\nEnter how many elements to be inserted in a tree\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(ptr, "%d", &val);
        root = insert(root, val);
    }
    inorder(root);
    fclose(ptr);
}