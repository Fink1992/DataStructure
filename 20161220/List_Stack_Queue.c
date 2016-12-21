#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;

void push(node **top, node *newNode);
void pop(node **top);
void insertQueue(node **front, node **rear, node *newNode);
void deleteQueue(node **front, node **rear);
void print(node *head);
int main(void)
{
//	node *top = NULL;
	node *newNode = NULL;
	node *front = NULL, *rear = NULL;
/*	newNode = (node *)malloc(sizeof(node));
	newNode->data = 3;
	push(&top, newNode);
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 5;
	push(&top, newNode);
	pop(&top);
	pop(&top);
*/	
	newNode = (node *)malloc(sizeof(node));
	newNode->data = 3;
	insertQueue(&front, &rear, newNode);

	newNode = (node *)malloc(sizeof(node));
	newNode->data = 5;
	insertQueue(&front, &rear, newNode);

	newNode = (node *)malloc(sizeof(node));
	newNode->data = 6;
	insertQueue(&front, &rear, newNode);

	print(front);

	deleteQueue(&front, &rear);
	deleteQueue(&front, &rear);
	deleteQueue(&front, &rear);

	return 0;
}

void push(node **top, node *newNode)
{
	node *p = *top;

	printf("push:%d\n", newNode->data);
	if (p == NULL) {
		newNode->next = NULL;
	} else {
		newNode->next = *top;	
	}
	*top = newNode;
}

void pop(node **top)
{
	node *p = *top;

	if (p == NULL)
		;
	else {
		printf("pop:%d\n", p->data);
		*top = p->next;
		free(p);
	}
}

void insertQueue(node **front, node **rear, node *newNode)
{
	if (*front == NULL) {
		*rear = newNode;
		*front = newNode;
		newNode->next = NULL;
	} else {
		(*rear)->next = newNode;
		*rear = newNode;
		newNode->next = NULL;
	}
}

void deleteQueue(node **front, node **rear)
{
	node *p = *front;

	if (p->next == NULL) {
		*rear = NULL;
		*front = NULL;
		free(p);
	} else {
		*front = (*front)->next;
		free(p);
	}
}

void print(node *head)
{
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
