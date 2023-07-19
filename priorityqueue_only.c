#include <stdio.h>
#include <stdlib.h>
#define max 10
struct priority
{
    int f;
    int r;
    int queue[max];
} s;
int isempty(struct priority *p)
{
    if (p->f == -1 && p->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct priority *p)
{
    if (p->r == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void priority(struct priority *p, int item)
{
    int pos;
    if (isfull(p))
    {
        printf("Queue is Full\n");
    }
    else
    {
        pos = p->r;
        p->r = p->r + 1;
        while (pos >= 0 && p->queue[pos] > item)
        {
            p->queue[pos + 1] = p->queue[pos];
            pos = pos - 1;
        }
        p->queue[pos + 1] = item;
        if (p->f == -1)
        {
            p->f = p->f + 1;
        }
    }
}
void display(struct priority *p)
{
    if (isempty(p))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = p->f+1; i <= p->r; i++)
        {
            printf("%d ", p->queue[i]);
        }
    }
}
int main()
{
    int n, data;
    struct priority * p;
    p->f = p->r = -1;
    p = &s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        priority(p, data);
    }
    display(p);
    return 0;
}
