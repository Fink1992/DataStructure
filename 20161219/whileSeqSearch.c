#include <stdio.h>

int seq_search(char [], int, char);

int main(void)
{
	char list[10] = "abcdefg";
	printf("%d\n", seq_search(list, 10, 'd'));
	return 0;
}

int seq_search(char list[], int length, char key)
{
	int i;
	for (i = 0; i < length; i++)
		if (key == list[i])
			return i;
	return -1;
}

