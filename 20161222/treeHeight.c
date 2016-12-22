#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
} node;

void tree_h(node *head, int *height);

int main(void)
{
	node *array[3] = {}, *newNode = NULL, *head = NULL;
	int datas[3] = {1, 2, 3}, i, height = 0;
	
	
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

	tree_h(head, &height);
	printf("Tree height: %d\n", height);
	for (i = 0; i < 3; i++) {
		free(array[i]);
	}
	return 0;
}

void tree_h(node *head, int *height)
{
	static int step = 0;
	if (head == NULL)
		return ;
	else {
		step++;
		if (step > *height)
			*height = step;
		tree_h(head->left, height);
		tree_h(head->right, height);
		step--;
	}
}
