#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5 // Maximum number of elements that can be stored

int top = -1, stack[MAX];
void push(FILE *ptr1, FILE *ptr2)
{
	int val;
	char ch;
	if (top == MAX - 1)
	{
		printf("\nStack is full!!");
	}
	else
	{
		// printf("\nEnter element to push:");
		// char ch = fgetc(ptr1);
		while ((ch = fgetc(ptr1) != EOF))
			putc(ch, ptr2);
		val = ch;
		// scanf("%d",&val);
		top = top + 1;
		stack[top] = val;
	}
}

void pop()
{
	if (top == -1)
	{
		printf("\nStack is empty!!");
	}
	else
	{
		printf("\nDeleted element is %d", stack[top]);
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
		printf("\nStack is\n");
		for (i = top; i >= 0; --i)
			printf("%d\n", stack[i]);
	}
}
void printRandoms(int lower, int upper, int count, FILE *ptr1)
{
	int i, ch;
	for (i = 0; i < count; i++)
	{
		int num = (rand() %
				   (upper - lower + 1)) +
				  lower;
		printf("%d ", num);
		fprintf(ptr1, "%d", num);
	}
}

int main()
{
	int lower = 20, upper = 99, count = 15;
	int ch;
	FILE *ptr1;
	FILE *ptr2;
	srand(time(0));
	ptr1 = fopen("heavy.txt", "r");
	ptr2 = fopen("stack4.txt", "a");
	printRandoms(lower, upper, count, ptr1);

	while (1)
	{
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			push(ptr1, ptr2);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("\nWrong Choice!!");
		}
	}
	fclose(ptr1);
	fclose(ptr2);
	return 0;
}
