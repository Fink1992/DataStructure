#include <stdio.h>
void rectangle(int, int, int);

int main(void)
{
	int n, m, d;
	printf("Please input number n:");
	scanf("%d", &n);
	printf("Please input number m:");
	scanf("%d", &m);
	printf("Please input number d:");
	scanf("%d", &d);
	rectangle(n, m, d);
	return 0;
}

void rectangle(int n, int m, int d)
{
	int i, j;
	if ((n > d << 1) && (m > d << 1)) {
		for (i = 0; i < d; i++) {
			for (j = 0; j < n; j++)
				printf("*");
			printf("\n");
		}
		for (i = 0; i < m - (d<<1); i++) {
			for (j = 0; j < d; j++)
				printf("*");
			for (j = 0; j < n - (d<<1); j++)
				printf(" ");
			for (j = 0; j < d; j++)
				printf("*");
			printf("\n");
		}
		for (i = 0; i < d; i++) {
			for (j = 0; j < n; j++)
				printf("*");
			printf("\n");
		}
	}
}
