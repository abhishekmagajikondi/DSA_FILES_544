#include <stdio.h>
#include <stdlib.h>
void read(int a[100], int n,FILE *ptr);
void display(int a[100], int n);
void repeating(int a[100], int n);
void main()
{
    int a[100], n, ch;
    FILE *ptr;
    printf("read the n value :\n");
    scanf("%d", &n);
    ptr = fopen("array.txt", "r");
    read(a, n ,ptr);
    while (1)
    {
        printf("1--display\n");
        printf("2--repeating\n");
        printf("3--exit\n");

        printf("enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
       {
        case 1:
            display(a, n);
            break;
        case 2:
            repeating(a, n);
            break;
        default:
            printf("invalid input\n");
            exit(0);
            break;
        }
    }
}
void read(int a[100], int n, FILE *ptr)
{
    int i,val;
    for (i = 0; i < n; i++)
    {
        //printf("Enter the %d element", i + 1);
        fscanf(ptr, "%d", &val);
        a[i]=val;
        //scanf("%d", &a[i]);
    }
    fclose(ptr);
}
void display(int a[100], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void repeating(int a[100], int n)
{
    int i, j,d, flag;
    int count;
    for (i = 0; i < n; i++)
    {
        count = 0;
        flag=0;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                if(a[j]!=0)
                {
                flag=1;
                d=a[i];
                a[j]=0;
                count++;
                }
            }
        }
        if(flag==1)
        printf("%d---%d\n", d, count+1);
        
    }
}
