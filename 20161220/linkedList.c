#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	} node;

node *insert(node *head, int data);
node *delete(node *head);
void updateList(node *head, int);
int countList(node *head);
void print(node *head);
node *reverseList(node *head);

int main(void)
{
	node *p = NULL;
	p =  insert(p, 1);
	p = insert(p, 2);
	printf("Before reverse:\n");
	print(p);
	p = reverseList(p);
	printf("After reverse:\n");
	print(p);
	p = delete(p);
	p = delete(p);
	return 0;	
}

int countList(node *head)
{
	int i = 1;
	node *p = head;
	
	if (p == NULL)
		return 0;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}

	return i;
}

node *insert(node *head, int i)
{
	node *p = head, *q;

	if (p == NULL) {
		p = (node *)malloc(sizeof(node));
		p->data = i;
		p->next = NULL;
		head = p;
	} else {
		while (p->next != NULL)
			p = p->next;
		q = malloc(sizeof(node));
		q->data = i;
		q->next = NULL;
		p->next = q;
	}
	return head;
}

node *delete(node *head)
{
	node *p, *q;
	p = head;
	if (p == NULL)
		;
	else if (p->next == NULL) {
		free(p);
		p = NULL;
		head = NULL;
	} else {
		while (p->next->next != NULL)
			p = p->next;
		q = p->next;
		p->next = NULL;
		free(q);
		q = NULL;
	}
	return head;
}

void updateList(node *head, int c)
{
	node *p = head;

	if (p != NULL) {
		while (p->next != NULL)
			p = p->next;
		p->data = c;
	} else
		printf("updateList failed. head = NULL\n");
}

node *reverseList(node *head)
{
	node *p = head;
	node *q = head;

	while (p != NULL) {
		if (p == q) {
			p = p->next;
			q->next = NULL;
		} else {
			q = p;
			p = p->next;
			q->next = head;
			head = q;
		}
	}
	return head;
}

void print(node *head)
{
	node *p = head;
	if (p == NULL)
		printf("p == NULL\n");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
