#include <stdio.h>

#define ROW 3
#define COL 4
#define MID 2

void matrix(int [][MID], int [][COL], int [][COL]);

int main(void)
{
	int i, j;
	int a[ROW][MID] = {{1, 1},
					   {2, 2},
					   {3, 3}};
	int b[MID][COL] = {{1, 2, 3, 4},
					   {1, 2, 3, 4}};

	int c[ROW][COL] = {};

	matrix(a, b, c);

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++)
			printf("%3d ", c[i][j]);
		printf("\n");	
	}
	return 0;
}

void matrix(int a[][MID], int b[][COL], int c[][COL])
{
	int i, j, k;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			for (k = 0; k < MID; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
