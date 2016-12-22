#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
} node;

void infix(node *head);

int main(void)
{
	node *array[3] = {}, *newNode = NULL, *head = NULL;
	int datas[3] = {1, 2, 3}, i;
	
	
	for (i = 0; i < 3; i++) {
		newNode = (node *)malloc(sizeof(node));
		newNode->data = datas[i];
		newNode->left = NULL;
		newNode->right = NULL;
		array[i] = newNode;
	}

	head = array[0];
	array[0]->right = array[2];
	array[0]->left = array[1];

	infix(head);

	for (i = 0; i < 3; i++) {
		free(array[i]);
	}
	return 0;
}

void infix(node *head)
{
	if (head->left != NULL)
		infix(head->left);
	printf("%d ", head->data);
	if (head->right != NULL)
		infix(head->right);
}
