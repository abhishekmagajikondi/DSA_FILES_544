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
        ptr->r++;
        ptr->arr[ptr->r] = value;
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
    }
}
int main()
{
    FILE *p;
    struct queue *ptr = &s;
    p=fopen("BFS_TRAVERSAL.txt","w");
    ptr->f = ptr->r = -1;
    int i=3;
    int visited[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
    int a[13][13] = {
       {0,1,1,0,0,0,0,0,0,0,0,0,0},
       {1,0,0,1,0,0,0,0,0,0,0,0,0},
       {1,0,0,1,0,0,0,0,0,0,0,0,0},
       {0,1,1,0,1,1,0,0,1,0,0,0,0},
       {0,0,0,1,0,0,0,0,0,0,0,0,0},
       {0,0,0,1,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,1,0,0,0,0},
       {0,0,0,0,0,0,0,0,1,0,0,0,0},
       {0,0,0,1,0,0,1,1,0,1,1,0,0},
       {0,0,0,0,0,0,0,0,1,0,0,1,0},
       {0,0,0,0,0,0,0,0,1,0,0,1,0},
       {0,0,0,0,0,0,0,0,0,1,1,0,1},
       {0,0,0,0,0,0,0,0,0,0,0,1,0},
    };
    fprintf(p,"%d\t",i);
    visited[i]=1;
    enqueue(ptr,3);//enqueue 1 for exploration
    while(!(isempty(ptr)))
    {
        int node = Dequeue(ptr);
        for (int j = 0; j < 13; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                  //printf("%d",j);
                  fprintf(p,"%d\t",j);
                  visited[j]=1;
                  enqueue(ptr,j);
            }
        }
    }
    fclose(p);
    return 0;
}
