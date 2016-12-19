#include <stdio.h>
#define MAXSIZE 10
int count(int [], int);

int main(void)
{
	int score[MAXSIZE] = {10, 20, 40, 20, 50, 10, 60, 30, 10, 10};

	printf("Different number:%d", count(score, 10));
	return 0;
}

int count(int s[], int size)
{
	int i, j, count = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				break;
		if (i == j)
			count++;
	}

	return count;
}
