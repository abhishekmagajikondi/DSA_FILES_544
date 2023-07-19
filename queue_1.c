#include <stdio.h>
#include <stdlib.h>
#define size 100

struct queue
{
    int f;
    int r;
    int arr[size];
} s;
int isempty(struct queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *ptr)
{
    if (ptr->r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue over flow \n");
    }
    else
    {
        scanf("%d", &value);
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}
int Dequeue(struct queue *ptr, int i)
{
    if (isempty(ptr))
    {
        printf("Queue under flow \n");
    }
    else
    {
        int a;
        ptr->f++;
        a = ptr->arr[ptr->f];
        printf("Dequeue %d= %d\n", i + 1, a);
    }
}
void display(struct queue *ptr)
{
    int i;
    for (i = ptr->f + 1; i <= ptr->r; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}
void peek(struct queue *ptr)
{
    int pos, j = 1;
    printf("Enter the position \n");
    scanf("%d", &pos);
    while (j != pos - 1)
    {
        j++;
    }
    printf("Peek element is %d\n", ptr->arr[j]);
}
void highest(struct queue *ptr)
{
    int h = 0;
    for (int i = 0; i <= ptr->r; i++)
    {
        if (ptr->arr[i] > h)
        {
            h = ptr->arr[i];
        }
    }
    printf("Highest = %d\n ", h);
}

int main()
{
    struct queue *ptr = &s;
    ptr->f = ptr->r = -1;
    int n, value, d;
    printf("Enter the n value : \n");
    scanf("%d", &n);
    printf("Enter the delete values : \n");
    scanf("%d", &d);
    for (int i = 0; i < n; i++)
    {
        enqueue(ptr, value);
    }
    printf("Queue before deleting :\n");
    display(ptr);
    peek(ptr);
    for (int i = 0; i < d; i++)
    {
        Dequeue(ptr, i);
    }
    highest(ptr);
    printf("Queue after deleting :\n");
    display(ptr);
    return 0;
}
