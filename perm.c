#include <stdio.h>
#include <stdlib.h>
void swap(char [], int, int);
void perm(char [], int, int);

int main(void)
{
	char list[10] = "1234";

	perm(list, 0, 3);
	return 0;
}

void perm(char s[], int begin, int end)
{
	int i;
	if (begin > end) {
		printf("error: begin > end\n");
		exit(-1);
	} else if (begin == end)
		printf("%s   ", s);
	else {
		for (i = begin; i <= end; i++) {
			swap(s, begin, i);
			perm(s, begin + 1, end);
			swap(s, begin, i);
		}
		printf("\n");
	}
}

void swap(char s[], int i, int j)
{
	int temp;

	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
