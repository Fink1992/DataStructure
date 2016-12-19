#include <stdio.h>
#include <stdlib.h>

void magic(int **, int);

int main(void)
{
	int **p, *ptr, n, i, j;
	
	printf("Input a magic number n:");
	scanf("%d", &n);

	p = (int **)malloc((n * sizeof(int *)) + n * n * sizeof(int));
	for (i = 0, ptr = (int*)(p+n); i < n; i++, ptr += n)
		*(p + i)= ptr;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			p[i][j] = 0;

	magic(p, n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%4d", p[i][j]);
		printf("\n");
	}
	free(p);
	return 0;
}

void magic(int **p, int n)
{
	int i = 0, j = n>>1, k, x, y;
	p[i][j] = 1;

	for (k = 2; k <= n*n; k++) {
		x = ((i - 1) < 0) ? n + i - 1 : i - 1;
		y = ((j - 1) < 0) ? n + j - 1 : j - 1;

		if (p[x][y])
			i++;	
		else {
			i = x;
			j = y;
		}	
		p[i][j] = k;	
	}	
}
