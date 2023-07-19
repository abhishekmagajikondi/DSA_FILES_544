#include <stdio.h>
#include <stdlib.h>
#define size 5
struct priority_queue
{
    int f;
    int r;
    int p[size];
    int arr[size];
} s;
int isempty(struct priority_queue *ptr)
{
    if (ptr->r == ptr->f == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct priority_queue *ptr)
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
void enqueue(struct priority_queue *ptr, int value, int a)
{
    if (isfull(ptr))
    {
        printf("The Queue is full\n");
    }
    else
    {
        int p;
        ptr->r++;
        ptr->p++;
        ptr->arr[ptr->r] = value;
        ptr->arr[ptr->p] = a;
    }
}
/*void dequeue(struct priority_queue *ptr)
{
   if(isempty(ptr))
   {
       printf("The Queue is empty\n");
   }
   else
   {
       int v;
       ptr->f++;
       v=ptr->arr[ptr->f];
       printf("dequeue = %d\n",v);
   }
}*/
void display(struct priority_queue *ptr)
{
    if (isempty(ptr))
    {
        printf("No element to print \n");
    }
    else
    {
        for (int i = ptr->f ; i <= ptr->r; i++)
        {
            printf("%d--%d\n", ptr->arr[i], ptr->p[i]);
        }
        printf("\n");
    }
}
int main()
{
    struct priority_queue *ptr = &s;
    ptr->f = ptr->r = -1;
    int n, a, p, value, d;
    printf("Enter the n value : \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&value,&a);
        enqueue(ptr, value, a);
    }
    display(ptr);
    return 0;
}
