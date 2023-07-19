#include<stdio.h>
#include<stdlib.h>
 
void generaterandom(int lower,int upper,int count,FILE *ptr)
{
    printf("Enter the lower\nEnter the upper\nEnter the count\n");
    scanf("%d%d%d",&lower,&upper,&count);
    for (int i = 0; i < count; i++)
    {
        int num= ((rand()%(upper-lower+1))-lower);
        fprintf(ptr,"%d\n",num);
    }
    fclose(ptr);
}
int main()
{
    FILE *ptr;
    ptr= fopen("generate.txt","w");
    int lower,upper,count;
    generaterandom(lower,upper,count,ptr);
    fclose(ptr);
    return 0;
}