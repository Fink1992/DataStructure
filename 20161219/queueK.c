#include <stdio.h>

int insertq(int *queue, int n, int *rear, int *queueNo, int data);
int deleteq(int *queue, int *front, int *queueNo, int *data);
void printQueue(int *queue, int front, int queueNo);
int deleteA(int *queue, int *front, int *rear, int *queueNo, int data);
int insertqK(int *queue, int n, int *rear, int k, int *queueNo, int data);
int deleteqK(int *queue, int n,int *rear, int *front, int k, int *queueNo, int *data);

int main(void)
{
	int queue[100] = {0, 0, 1, 2, 3, 4, 1, 5};
	int rear = 7, front = 1, queueNo = 6, data;
	
	printQueue(queue, front, queueNo);
	insertqK(queue, 100, &rear, 3, &queueNo, 6);
	printQueue(queue, front, queueNo);
	deleteqK(queue, 100,&rear, &front, 2, &queueNo, &data);
	printQueue(queue, front, queueNo);
	printf("%d\n", data);
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

int insertqK(int *queue, int n, int *rear, int k, int *queueNo, int data)
{
	int i;
	if (*queueNo == n) {
		printf("error: queue full\n");
		return 0;
	}
	if (k > *queueNo) {
		printf("error: K > queueNo");
		return 0;
	}
	for (i = 0; i < *queueNo; i++) {
		if (i == 0)
			++*rear;
		if ((*queueNo - i) == k) {
			queue[(*rear - i + n) % n] = data;
			break;
		} else
			queue[(*rear - i + n) % n] = queue[(*rear - i + n - 1) % n];
	}
	++*queueNo;
	return 1;
}

int deleteqK(int *queue, int n,int *rear, int *front, int k, int *queueNo, int *data)
{
	int i;
	
	*data = queue[(*front + k) % n];
	for (i = 0; i < *queueNo - k; i++) 
		queue[(*front + i + k) % n] = queue[(*front + k + i + 1) % n];
	--*rear;
	--*queueNo;
	return 0;	
}
