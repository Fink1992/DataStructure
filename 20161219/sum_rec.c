#include <stdio.h>

int sum(int *, int);

int main(void)
{
	int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("%d\n", sum(num, 10));
	return 0;
}

int sum(int *s, int n)
{
	return (n == 1) ? s[0] : s[0] + sum(++s, n - 1);
}
