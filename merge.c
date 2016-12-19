#include <stdio.h>

int merge(int*, int*, int*);

int main(void)
{
	int len, i;
	int a[] = {128, 34, 23, 17, 10, 0};
	int b[] = {1352, 127, 34, 23, 17, 9, 0};
	int out[13];

	len = merge(a, b, out);
	for (i = 0; i <= len; i++)
		printf("%d ", out[i]);
	printf("\n");	
	return 0;
}

int merge(int *a, int *b, int *out)
{
	int i = 0;
	while (*a || *b) {	/* a[i] or b[i] isn't equal to zero. */
		if (*a > *b) {
			*out++ = *a;
			a++;
		} else if (*a < *b) {
			*out++ = *b;
			b++;
		} else {
			*out++  = *a;
			a++;
			b++;
		}
		i++;
	}
	while (*a) {	/* a[i] isn't zero. */
		*out++ = *a;
		a++;
		i++;
	}
	while (*b) {	/* b[i] isn't zero. */
		*out++ = *b;
		b++;
		i++;
	}
	*out = 0;
	return i;
}
