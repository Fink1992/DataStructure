#include <stdio.h>

int binary(int[], int, int, int);

int main(void)
{
	int list[10] = {5, 12, 34, 56, 76, 81, 99, 123, 145, 168};

	printf("Position:%d\n", binary(list, 34, 0, 9));
	return 0;
}

int binary(int list[], int item, int left, int right)
{
	int mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (item == list[mid])
			return mid;
		else if (item < list[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
