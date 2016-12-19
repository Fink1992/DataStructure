#include <stdio.h>

#define MAXSIZE 10

int isStackEmpty(int *, int);
int isStackFull(int*, int, int);
void printStack(int *, int);
int push(int*, int, int*, int);
int pop(int*, int *, int *);
int pushK(int *stack, int n, int *top, int k, int data);
int popK(int *stack, int *top, int k, int *data);

int main(void)
{
	int stack[MAXSIZE] = {'A', 'B', 'D', 'E'};	
	int top = 3, data;

	printStack(stack, top);
	if (pushK(stack, MAXSIZE, &top, 3, 'C'))
		printStack(stack, top);
	else
		printf("error: pushK failure.\n");

	if (popK(stack, &top, 3, &data)) {
		printStack(stack, top);
		printf("popK: %c\n", data);
	} else
		printf("error: popK failure.\n");

	return 0;
}

int isStackEmpty(int *stack, int top)
{
	return (top == -1) ? 1 : 0;
}

int isStackFull(int *stack, int n, int top)
{
	return (top == n - 1) ? 1 : 0;
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

int pushK(int *stack, int n, int *top, int k, int data)
{
	int val[MAXSIZE], sp = -1, data2;
	
	if (k - 1 > *top)
		return 0;
	while (*top >= k - 1) {
		pop(stack, top, &data2);
		push(val, MAXSIZE, &sp, data2);
	}
	push(stack, MAXSIZE, top, data);

	while (pop(val, &sp, &data2))
		push(stack, MAXSIZE, top, data2);	
	return 1;
}

int popK(int *stack, int *top, int k, int *data)
{
	int val[MAXSIZE], sp = -1, data2;

	if (k - 1 > *top)
		return 0;
	
	while (*top > k-1) {
		pop(stack, top, &data2);
		push(val, MAXSIZE, &sp, data2);
	}

	pop(stack, top, data);

	while (pop(val, &sp, &data2))
		push(stack, MAXSIZE, top, data2);
	return 1;
}
