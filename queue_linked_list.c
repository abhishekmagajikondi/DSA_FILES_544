#include <stdlib.h>
#include <stdio.h>

struct stacklist
{
    int data;
    struct stacklist *next;
};
struct stacklist *rear = NULL;
struct stacklist *front = NULL;
void enqueue(int x)
{
    struct stacklist *newnode;
    newnode = (struct stacklist *)malloc(sizeof(struct stacklist));
    newnode->data = x;
    newnode->next = NULL;
    if (rear == 0 && front ==0)
    {
        rear = front = newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void display()
{
    struct stacklist *temp;
    if (rear == 0 && front == 0)
    {
        printf("queue is empty\n");
    }
    else
        temp = front;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void dequeue()
{
    if (rear == 0)
    {
        printf("No list is present\n");
    }
    else
    {
        printf("%d=dequeued\n", front->data);
        front = front->next;
    }
}
void printRandoms(FILE *ptr)
{
    int i, lower, upper, count;
    printf("Enter how many numbers you want: \n");
    scanf("%d", &count);
    printf("Enter lower range of number: \n");
    scanf("%d", &lower);
    printf("Enter upper range of number: \n");
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
int main()
{
    int ch, data;
    FILE *ptr;
    ptr = fopen("queue_list.txt", "w");
    printRandoms(ptr);
    ptr = fopen("queue_list.txt", "r");
    while (1)
    {

        printf("\n1--enqueue\n");
        printf("2--dequeue\n");
        printf("3--display\n");

        printf("Enter your choice \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            fscanf(ptr, "%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
            break;
        }
    }
    fclose(ptr);
    return 0;
}