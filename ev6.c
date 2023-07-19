#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

struct queue
{
    int f;
    int r;
    char *arr[size];
    char *ch;
    char *name[size];
    char *final[size];
    char *w[size];
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
void enqueue(struct queue *ptr, char value[20], char data[size])
{
    if (isFull(ptr))
    {
        printf("Queue over flow \n");
    }
    else
    {
       
        if (ptr->f == -1)
        {
            ptr->f++;
        }
        scanf("%s", value);
        scanf(" %c",&data);
        ptr->r++;
        ptr->arr[ptr->r] = value;
        ptr->ch[ptr->r] = data;
    }
}
int Dequeue(struct queue *ptr)
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
        return a;
    }
}
void divide(struct queue *ptr, int c, int v, int q)
{
    v = q = c = 0;
    for (int i = 0; i <= ptr->r; i++)
    {
        if (ptr->ch[i] == 'N')
        {
            ptr->name[v] = ptr->arr[i];
            v++;
            return v;
           
        }
        else if (strcmp(ptr->ch[i],'W')==0)
        {
            strcpy(ptr->final[c],ptr->arr[i]);
            c++;
            printf("%d", c);
             return c;
        }
        else if (strcmp(ptr->ch[i],'C')==0)
        {
            strcpy(ptr->w[q],ptr->arr[i]);
            q++;
            printf("%d", q);
              return q;
        }
    }
}
void display(struct queue *ptr, int c, int v, int q)
{
    int i;
    printf("Line 1 :");
    for (i = 0; i < v; i++)
    {
        printf("%s ", ptr->name[i]);
        putchar(ptr->name[i]);
    }
    printf("\n");
    printf("Line 2 :");
    for (i = 0; i < c; i++)
    {
        printf("%s ", ptr->final[i]);
    }
    printf("\n");
    printf("Line 3 :");
    for (i = 0; i < q; i++)
    {
        printf("%s ", ptr->w[i]);
    }
    printf("\n");
}
int main()
{
    struct queue *ptr = &s;
    ptr->f = ptr->r = -1;
    int n, c = 0, v = 0, q = 0;
    char value[20], data[20];
    printf("Enter the n value : \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        enqueue(ptr, value, data);
    }
    
    divide(ptr, c, v, q);
    display(ptr, c, v, q);
    return 0;
}
