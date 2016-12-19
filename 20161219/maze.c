#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COL 7
#define MAXSIZE 100

void maze(int (*s)[], int, int, int, int);
void push(int , int);
void pop(int *x, int *y);

int val[ROW * COL][2];
int top = -1;

int main(void)
{
	int s[ROW][COL] = {{1, 1, 1, 1, 1, 1, 1},
					   {1, 0, 0, 0, 0, 0, 1},
				   	   {1, 0, 1, 0, 1, 0, 1},
					   {1, 0, 0, 1, 0, 1, 1},
					   {1, 1, 0, 1, 0, 1, 1},
					   {1, 0, 0, 0, 0, 0, 1},
					   {1, 1, 1, 1, 1, 1, 1}};
	maze(s, 1, 1, 5, 5);
	return 0;
}
void maze(int (*s)[COL], int origin_x, int origin_y, int end_x, int end_y)
{
	int now_x = origin_x;
	int now_y = origin_y;

	while (now_x != end_x || now_y != end_y) {
		if (!s[now_x][now_y - 1]) {
			push(now_x, now_y);
			s[now_x][now_y] = 1;
			now_y--;
		} else if (!s[now_x - 1][now_y]) {
			push(now_x, now_y);
			s[now_x][now_y] = 1;
			now_x--;
		} else if (!s[now_x][now_y + 1]) {
			push(now_x, now_y);
			s[now_x][now_y] = 1;
			now_y++;
		} else if (!s[now_x + 1][now_y]) {
			push(now_x, now_y);
			s[now_x][now_y] = 1;
			now_x++;
		} else if (now_x == origin_x && now_y == origin_y)
			break;
		else {
			s[now_x][now_y] = 1;
			pop(&now_x, &now_y);
		}
	}
	if (now_x == end_x && now_y == end_y)
		printf("end is (%d, %d) \n", now_x, now_y);
	else
		printf("Can't find the end\n");
}

int **new2Darray(int row, int col)
{
	int **p, *ptr, i;

	p = (int **)malloc(row * sizeof(int *) + row * col * sizeof(int));

	for (i = 0, ptr = (int *)(p + row); i < row; i++, ptr += col)
		*(p + i) = ptr;
	return p;
}

void push(int x, int y)
{
	if (top < MAXSIZE - 1) {
		top++;
		val[top][0] = x;
		val[top][1] = y;
	} else
		printf("error: val full\n");
}

void pop(int *x, int *y)
{
	if (top < 0)
		printf("error: val empty\n");
	else {
		*x = val[top][0];
		*y = val[top][1];
		top--;
	}
}


