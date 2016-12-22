#include <stdio.h>
#include <string.h>

void print(char *string[], int);
void quicksort(char **, int, int);
void swap(char **, int, int);

int main(void)
{
	char *string[5] = {"Tom", "John", "Mary", "Sam", "Kent"};
	
	print(string, 5);
	quicksort(string, 0, 4);
	print(string, 5);
}

void print(char *string[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n", string[i]);
	printf("\n\n===============\n\n");
}

void quicksort(char *string[], int left, int right)
{
	int mid, last, i;

	if (left > right)
		return ;
	else {
		mid = (left + right) / 2;
		i = last = left;
		swap(string, mid, left);
		while (i <= right) {
			if (strcmp(string[left], string[i]) > 0) 
				swap(string, ++last, i);
			i++;	
		}
		swap(string, last, left);
		quicksort(string, left, last-1);
		quicksort(string, last+1, right);
	}
}

void swap(char *string[], int i, int j)
{
	char *temp;
	temp = string[i];
	string[i] = string[j];
	string[j] = temp;
}
