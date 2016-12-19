#include <stdio.h>

int insertq(int *queue, int n, int *rear, int *queueNo, int data);
int deleteq(int *queue, int *front, int *queueNo, int *data);
void printQueue(int *queue, int front, int queueNo);
int deleteA(int *queue, int *front, int *rear, int *queueNo, int data);

int main(void)
{
	int queue[100] = {0, 0, 1, 2, 3, 4, 1, 5};
	int rear = 7, front = 1, queueNo = 6, data;
	
	printQueue(queue, front, queueNo);
	deleteA(queue, &front, &rear, &queueNo, 1);
	printQueue(queue, front, queueNo);
	return 0;	
}

int insertq(int *queue, int n, int *rear, int *queueNo, int data)
{
	if (*rear >= n - 1)
		return 0;
	queue[++*rear] = data;
	++*queueNo;
	return 1;
}

int deleteq(int *queue, int *front, int *queueNo, int *data)
{
	if (*queueNo == 0)
		return 0;
	*data = queue[++*front];
	--*queueNo;
	return 1;
}

void printQueue(int *queue, int front, int queueNo)
{
	int i;

	for (i = 0; i < queueNo; i++)
		printf("%d ", queue[++front]);
	printf("\n");
}

int deleteA(int *queue, int *front, int *rear, int *queueNo, int data)
{
	int i = *front + 1, gap;

	for (i = *front + 1, gap = 0; i <= *rear; i++) {
		if (queue[i] == data)
			gap++;
		else
			queue[i-gap] = queue[i];
	}
	*rear -= gap;
	*queueNo -= gap;
	return gap;
}
