#include<stdio.h>
int main()
{
    int p,q,a[10][10],b[10][10];
    FILE *ptr=NULL;
    ptr=fopen("DSA.txt","r");
    printf("Enter the rows and columns of a matrix: \n");
    scanf("%d%d",&p,&q);
    printf("The first matrix\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            char ch = fgetc(ptr);
            a[i][j]=ch;
            printf(" %c\t",a[i][j]);
        }
        printf("\n"); 
    }
    printf("The matrix after transposed: \n");
      for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            
            b[i][j]=a[j][i];
            printf(" %c\t",b[i][j]);
        }
        printf("\n");
        
    }
    fclose;
}