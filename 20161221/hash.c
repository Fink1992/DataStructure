#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
	int data;
	struct bucket *next;
} bucket;

int hashf(int);

int main(void)
{
	bucket * overflow[9], *newNode = NULL, *p = NULL;
	int data[9] = {5, 28, 19, 15, 20, 33, 12, 17, 10};
	int index, i;

	for (i = 0; i < 9; i++) {
		overflow[i] = NULL;
	}
	for (i = 0; i < 9; i++) {
		newNode = (bucket *)malloc(sizeof(bucket));
		newNode->data = data[i];
		index = hashf(data[i]) % 9;
		p = overflow[index];
		if (p == NULL) {
			overflow[index] = newNode;
			newNode->next = NULL;
		} else {
			while (p->next != NULL)
				p = p->next;
			p->next = newNode;
			newNode = NULL;
		}
	}
	
	for (i = 0; i < 9; i++) {
		p = overflow[i];
		printf("bucket[%d]:", i);
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}

	for (i = 0; i < 9; i++) {
		while ((p = overflow[i]) != NULL) {
			overflow[i] = p->next;
			free(p);
		}
	}
	return 0;
}

int hashf(int key)
{
	return key % 9;
}
