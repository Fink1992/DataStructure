#include <stdio.h>

void bubblesort(int *v, int len);
void swap(int *v, int, int);

int main(void)
{
	int v[10] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
	int i;
	bubblesort(v, 10);

	for (i = 0; i < 10; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}

void bubblesort(int v[], int len)
{
	int i, j, flag;

	for (i = len - 1; i > 0; i--) {
		flag = 0;
		for (j = 0; j < i; j++) {
			if (v[j+1] < v[j]) {
				swap(v, j+1, j);
				flag = 1;
			}
		}
		if (flag == 0)
			return ;
	}
}

void swap(int *v, int i, int j)
{
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
