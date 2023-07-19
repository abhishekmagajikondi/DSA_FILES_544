#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10 // Maximum number of elements that can be stored

int top = -1, stack[MAX];
void push(FILE *ptr1, FILE *ptr2,FILE *ptr3,FILE *ptr5)
{
    int val;
    if (top == MAX - 1)
    {
        printf("\nStack is full!!");
    }
    else
    {
        fscanf(ptr1, "%d",&val);
        fprintf(ptr2, "%d\n", val);
        fprintf(ptr3, "%d\n", val);
        fprintf(ptr5, "%d\n", val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop(FILE *ptr3,FILE *ptr4,FILE *ptr5)
{
    int valuu;
    if (top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nDeleted element is %d", stack[top]);
        fprintf(ptr4,"%d\n",stack[top]);
        fprintf(ptr5,"%d\n",stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nStack is...\n");
        for (i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}
void printRandoms(int lower, int upper, int count, FILE *ptr1)
{
    int i;
    printf("enter count\n");
    printf("enter lower\n");
    printf("enter upper\n");
    scanf("%d",&count);
    scanf("%d",&lower);
    scanf("%d",&upper);
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
    FILE *ptr1, *ptr2,*ptr3,*ptr4,*ptr5;
    int lower = 20, upper = 99, count = 10;
    ptr1 = fopen("input.txt", "w");
    ptr2 = fopen("stack.txt", "w");
    ptr3 = fopen("push.txt", "w");
    ptr4 = fopen("pop.txt", "w");
    ptr5 = fopen("alloperations.txt", "w");
    srand(time(0));
    printRandoms(lower, upper, count, ptr1);
    ptr1 = fopen("input.txt", "r");
    int ch;
    while (1)
    {
        printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(ptr1,ptr2,ptr3,ptr5);
            break;
        case 2:
            pop(ptr3,ptr4,ptr5);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice");
        }
    }
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    fclose(ptr5);
    return 0;
}