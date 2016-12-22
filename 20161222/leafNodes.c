#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
} node;

int leafnumber(node *head);

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

	if (!leafnumber(head))
			printf("empty tree\n");

	for (i = 0; i < 3; i++) {
		free(array[i]);
	}
	return 0;
}

int leafnumber(node *head)
{
	static int number = 0;
	int i, j;
	if (head == NULL)
		return 0;
	i = leafnumber(head->left);
	j = leafnumber(head->right);
	if (!i && !j)
		printf("This is leaf:%d , sum = %d\n", head->data, ++number);	
	return 1;
}
