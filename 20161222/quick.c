#include <stdio.h>

void quicksort(int *v, int left, int right);
void swap(int *v, int i, int j);
void print(int *v, int n);

int main(void)
{
	int v[10] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
	print(v, 10);
	quicksort(v, 0, 9);
	print(v, 10);	
	return 0;
}

void quicksort(int *v, int left, int right)
{
	int mid, last, i;

	if (left > right)
		;
	else {
		mid = (left + right) / 2;
		swap(v, left, mid);
		i = last = left;
		while (i <= right) {
			if (v[left] > v[i])
				swap(v, ++last, i);
			i++;
		}
		swap(v, last, left);
		quicksort(v, left, last - 1);
		quicksort(v, last + 1, right);
	}
}

void swap(int *v, int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void print(int *v, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");	
}
