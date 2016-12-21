#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} node;

void print(node *head);

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5}, i;
	node *head = NULL, *newNode, *p;

	for (i = 0; i < 5; i++) {
		newNode = (node *)malloc(sizeof(node));
		newNode->data = a[i];
		if (head == NULL) {
			head = newNode;
			newNode->next = NULL;
			continue;
		}
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = newNode;
		newNode->next = NULL;
	}
	p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	return 0;
}
