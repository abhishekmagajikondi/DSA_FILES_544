#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
struct circularQ
{
    int f;
    int r;
    int arr[size];
} s;
int isempty(struct circularQ *ptr)
{
    if (ptr->f == ptr->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct circularQ *ptr)
{
    if ((ptr->r + 1) % size == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct circularQ *ptr,FILE *ptr1)
{
    int val;
    if (isfull(ptr))
    {
        printf("Sorry queue is full\n");
    }
    else
    {
        if (ptr->f == -1)
        {
            ptr->f++;
        }
        fscanf(ptr1, "%d", &val);
        ptr->r = (ptr->r + 1) % size;
        ptr->arr[ptr->r] = val;
         printf("Enqueue Element is = %d\n",val);
    }
}
void display(struct circularQ *ptr)
{
    if (isempty(ptr))
    {
        printf("cant display queue is empty\n");
    }
    else
    {
        int i;
        for (i = ptr->f; i != ptr->r; i = (i + 1) % size)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("%d ", ptr->arr[i]);
        printf("\n");
    }
}
void dequeue(struct circularQ *ptr)
{
    int v;
    if (isempty(ptr))
    {
        printf("Cant dequeue\n");
    }
    else if (ptr->f == ptr->r)
    {
        v = ptr->arr[ptr->f];
        ptr->f == ptr->r == -1;
        printf("Dequeue = %d\n", v);
    }
    else
    {
        v = ptr->arr[ptr->f];
        ptr->f = (ptr->f + 1) % size;
        printf("Dequeue = %d\n", v);
    }
}
void printRandoms(int lower, int upper, int count, FILE *ptr1)
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
        fprintf(ptr1, "%d\n", num);
    }
    fclose(ptr1);
}
int main()
{
    FILE *ptr1;
    struct circularQ *ptr = &s;
    ptr->f = ptr->r = -1;
    int ch, val;
    int lower = 20, upper = 99, count = 10;
    ptr1 = fopen("readcirqueue.txt", "w");
    srand(time(0));
    printRandoms(lower, upper, count, ptr1);
    ptr1 = fopen("readcirqueue.txt", "r");
    while (1)
    {
        printf("\n1--enqueue\n");
        printf("2--dequeue\n");
        printf("3--display\n");
        printf("4--exit\n");
        printf("Enter ur choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue(ptr,ptr1);
            break;
        case 2:
            dequeue(ptr);
            break;
        case 3:
            display(ptr);
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }
    fclose(ptr1);
    return 0;
}
