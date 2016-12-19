#include <stdio.h>
int evenSum_rec(int);
int evenSum_tail(int, int);
int evenSum_iter(int);
int main(void)
{
	int number;	
	do {
	printf("Input a number :");
	scanf("%d", &number);
	if ( number > 2)
		break;
	} while (1);
	printf("Recursive version:%d\nTail Recursive version:%d\nIterative version:%d\n", evenSum_rec(number), evenSum_tail(number, 0), evenSum_iter(number));
	return 0;
}

int evenSum_rec(int n)	/* recursive version */
{
	if ( n & 1)
		--n;
	return (n == 0) ? 0 : evenSum_rec(n-2) + n;
}

int evenSum_tail(int n, int sum)
{
	if (n & 1)
		--n;
	return (n == 0) ? sum : evenSum_tail(n-2, sum + n);
}
int evenSum_iter(int n)	/* iterative version */
{
	int i, sum = 0;
	if (n & 1)
		--n;
	for (i = 0; i <= n; i += 2)
		sum += i;
	return sum;
}

