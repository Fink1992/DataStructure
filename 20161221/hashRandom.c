#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKETSIZE 100
typedef struct bucket {
	int data;
	struct bucket *next;
} bucket;

int hashf(int);
void print(bucket *overflow[]);
int main(void)
{
	bucket * overflow[BUCKETSIZE], *newNode = NULL, *p = NULL, *q = NULL;
	int index, i, number;

	srand(time(NULL));	
	for (i = 0; i < BUCKETSIZE; i++) {
		overflow[i] = NULL;
	}
	for (i = 0; i < 100; i++) {
		p = q = NULL;
		while(1) {
			number = (rand() % 100) + 1;
			index = hashf(number);
			p = overflow[index];
			if (p == NULL)
				break;
			else {
				while (p->data != number) {
					q = p;
					p = p->next;
					if (p == NULL)
						break;
				}
			}
		}
		newNode = (bucket *)malloc(sizeof(bucket));
		newNode->data = number;
		if (q == NULL) {
			overflow[index] = newNode;
			newNode->next = NULL;
		} else {
			q->next = newNode;
			newNode->next = NULL;
		}
	}
	
	print(overflow);	

	for (i = 0; i < BUCKETSIZE; i++) {
		while ((p = overflow[i]) != NULL) {
			overflow[i] = p->next;
			free(p);
		}
	}
	return 0;
}

int hashf(int key)
{
	return key % 100;
}

void print(bucket *overflow[])
{
	int i;
	bucket *p = NULL;
	for (i = 0; i < BUCKETSIZE; i++) {
		p = overflow[i];
		printf("bucket[%d]:", i);
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}

}
