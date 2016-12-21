#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *pre;
} node;

void sort(node **head, node *newNode);
void print(node *head);

int main(void)
{
	node *array[4], *head = NULL;	
	int answer[4] = {4, 2, 3, 1}, i;	

	for (i = 0; i < 4; i++) {
		array[i] = (node *)malloc(sizeof(node));
		array[i]->data = answer[i];
		sort(&head, array[i]);
	}
	print(head);

	for (i = 0; i < 4; i++) {
		free(array[i]);
	}
	return 0;
}

void sort(node **head, node *newNode)
{
	node *p = *head, *q = NULL;

	if (p == NULL) {
		*head = newNode;
		(*head)->next = NULL;
		(*head)->pre = NULL;
	} else {
		while (p != NULL && (p->data < newNode->data)) {
			q = p;
			p = p->next;
		}
		if (q == NULL) {
			newNode->next = p;
			newNode->pre = NULL;
			p->pre = newNode;
			*head = newNode;
		} else if (p == NULL) {
			newNode->next = NULL;
			newNode->pre = q;
			q->next = newNode;
		} else {
			q->next = newNode;
			newNode->pre = q;
			newNode->next = p;
			p->pre = newNode;
		}
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
