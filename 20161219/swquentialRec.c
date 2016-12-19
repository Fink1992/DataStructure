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
	if (*list == key)
		return 0;
	return seq_search(list + 1, length - 1, key) + 1;
}
