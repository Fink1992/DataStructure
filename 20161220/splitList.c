#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;

node *insert(node *head, int);
node *delete(node *head);
void print(node *head);
void split(node *h, node **h1, node **h2);
node *deleteAll(node *head);
int main(void)
{
	node *p = NULL, *p1 = NULL, *p2 = NULL;
	p = insert(p, 3);
	insert(p, 4);
	insert(p, 5);
	insert(p, 7);
	insert(p, 8);
	
	print(p);
	split(p, &p1, &p2);

	print(p1);
	print(p2);
	p1 = deleteAll(p1);
	p2 = deleteAll(p2);
	return 0;
}

node *insert(node *head, int i)
{
	node *p = head, *q = NULL;
	if (p == NULL) {
		q = (node *)malloc(sizeof(node));
		q->data = i;
		q->next = NULL;
		head = q;
		return head;
	}
	while (p->next != NULL)
		p = p->next;
	q = (node *)malloc(sizeof(node));
	q->data = i;
	q->next = NULL;
	p->next = q;
	return head;	
}

node *delete(node *head)
{
	node *p = head, *q = NULL;

	if (p == NULL)
		return head;
	if (p->next == NULL) {
		free(p);
		head = NULL;
		return head;
	}
	while (p->next->next != NULL)
		p = p->next;
	q = p->next;
	p->next = p->next->next;
	free(q);
	return head;
}

void split(node *h, node **h1, node **h2)
{
	node *p = h, *h1p = NULL, *h2p = NULL;

	while (p != NULL) {
		if (p->data % 2) {
			if (*h1 == NULL) {
				*h1 = p;
				h1p = *h1;
				p = p->next;
				h1p->next = NULL;
			} else {
				h1p->next = p;
				p = p->next;
				h1p = h1p->next;
				h1p->next = NULL;
			}
		} else {
			if (*h2 == NULL) {
				*h2 = p;
				h2p = *h2;
				p = p->next;
				(*h2)->next = NULL;
			} else {
				h2p->next = p;
				p = p->next;
				h2p = h2p->next;
				h2p->next = NULL;
			}
		}
	}
}

node *deleteAll(node *head)
{
	node *p = head;
	while (head != NULL) {
		head = head->next;
		free(p);
		p = head;
	}
	return head;
}

void print(node *head)
{
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

