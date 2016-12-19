#include <stdio.h>
void triangle1(void);
void triangle2(void);
void triangle3(void);
void triangle4(void);

int main(void)
{
	triangle1();
	triangle2();
	triangle3();
	triangle4();
	return 0;
}

void triangle1(void)
{
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j <= i; j++)
			printf("%d", i + 1);
		printf("\n");
	}
}

void triangle2(void)
{
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5-i; j++)
			printf(" ");
		for (j = 5-i; j < 6; j++)
			printf("%d", i + 1);
		printf("\n");
	}
}

void triangle3(void)
{
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - i; j++)
			printf("%d", i + 1);
		printf("\n");
	}
}

void triangle4(void)
{
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < i; j++)
			printf(" ");
		for ( ; j < 5; j++)
			printf("%d", i + 1);
		printf("\n");
	}
}
