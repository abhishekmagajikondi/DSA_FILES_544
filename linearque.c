#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
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
void enqueue(struct queue *ptr,FILE *ptr1)
{
    int val;
    if (isFull(ptr))
    {
        printf("Queue over flow \n");
    }
    else
    {
        fscanf(ptr1, "%d", &val);
        ptr->r++;
        ptr->arr[ptr->r] = val;
        printf("Enqueue Element is = %d\n",val);
    
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
    int ch,i;
    FILE *ptr1;
    struct queue *ptr = &s;
    ptr->f = ptr->r = -1;
    int lower = 20, upper = 99, count = 10;
    ptr1 = fopen("readqueue.txt", "w");
    srand(time(0));
    printRandoms(lower, upper, count, ptr1);
    ptr1 = fopen("readqueue.txt", "r");
    while (1)
    {
        printf("\n\n1.enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
           enqueue(ptr, ptr1);
            break;
        case 2:
            Dequeue(ptr, i);
            break;
        case 3:
            display(ptr);
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice");
        }
    }
    fclose(ptr1);
    return 0;
}
