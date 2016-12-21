#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *pre;
	struct Node *next;
} node;
void insertDoubleList(node **head, node *p, node *q);
void deleteDoubleList(node **head, node *p);
void print(node *head);

int main(void)
{
	node *n1, *n2, *n3, *n4, *n5, *head = NULL;	
	
	n1 = (node *)malloc(sizeof(node));
	n1->data = 1;
	n2 = (node *)malloc(sizeof(node));
	n2->data = 2;
	n3 = (node *)malloc(sizeof(node));
	n3->data = 3;
	n4 = (node *)malloc(sizeof(node));
	n4->data = 4;
	n5 = (node *)malloc(sizeof(node));
	n5->data = 5;

	insertDoubleList(&head, n1, n1);
	insertDoubleList(&head, n1, n2);
	insertDoubleList(&head, n2, n3);
	insertDoubleList(&head, n3, n4);
	insertDoubleList(&head, n2, n5);

	print(head);

	deleteDoubleList(&head, n2);
	print(head);
	deleteDoubleList(&head, n1);
	print(head);
	deleteDoubleList(&head, n5);
	print(head);
	deleteDoubleList(&head, n4);
	print(head);
	deleteDoubleList(&head, n3);
	return 0;
}

void insertDoubleList(node **head, node *p, node *q)
{
	if (*head == NULL) {
		*head = q;
		q->pre = NULL;
		q->next = NULL;
	} else if ((*head)->next == NULL) {
			(*head)->next = q;
			q->pre = *head;
			q->next = NULL;	
	} else {
		if (p->next == NULL) {
			p->next = q;
			q->pre = p;
			q->next = NULL;
		} else {
			p->next->pre = q;
			q->next = p->next;
			p->next = q;
			q->pre = p;
		}
	}
}
void deleteDoubleList(node **head, node *p)
{
	if (*head == NULL)
		;
	else if (((*head)->next) == NULL) {
		free(*head);
		*head = NULL;
	} else {
		if (p == *head) {
			*head =	p->next;
			(*head)->pre = NULL;
			free(p);
		} else if (p->next == NULL) {
			p->pre->next = NULL;
			free(p);
		} else {
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
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
