#include <stdio.h>

#define MAXSIZE 10

int isStackEmpty(int *, int);
int isStackFull(int*, int, int);
void printStack(int *, int);
int push(int*, int, int*, int);
int pop(int*, int *, int *);

int main(void)
{
	int stack[MAXSIZE] = {'A', 'C', 'B', 'A', 'D', 'F'}, val[MAXSIZE];
	int top = 5, sp = -1, data, n;

	while (pop(stack, &top, &data))
		if (data != 'A')
			push(val, MAXSIZE, &sp, data);
	while (pop(val, &sp, &data))
		push(stack, MAXSIZE, &top, data);
	
	printStack(stack, top);
	return 0;
}

int isStackEmpty(int *stack, int top)
{
	return (top < 0) ? 1 : 0;
}

int isStackFull(int *stack, int n, int top)
{
	return (top >= n - 1) ? 1 : 0;
}

void printStack(int *stack, int top)
{
	int i;
	for (i = 0; i <= top; i++)
		printf("%c ", stack[i]);
	printf("\n");
}

int push(int *stack, int n, int *top, int data)
{
	if (isStackFull(stack, n, *top))
		return 0;
	stack[++(*top)] = data;
	return 1;
}

int pop(int *stack, int *top, int *data)
{
	if (isStackEmpty(stack, *top))
		return 0;
	*data = stack[(*top)--];
	return 1;
}
