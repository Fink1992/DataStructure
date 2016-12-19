#include <stdio.h>

int main(void)
{
	int number, i, j;
	
	do {
		printf("Please input an odd number:");
		scanf("%d", &number);
		if ((number & 1) && number > 1)
			break;
		else
			printf("The number %d is not an odd number\n", number);
	} while (1);
			for (i = 0; i < (number >> 1); i++) {
				for (j = 0; j < (number >> 1) - i; j++)
					printf(" ");
				for (j = 0; j < (i << 1) + 1; j++)
					printf("*");
				printf("\n");
			}
			for (i = 0; i < number; i++)
				printf("*");
			printf("\n");
			for (i = 0; i < (number >> 1); i++) {
				for (j = 0; j < i + 1; j++)
					printf(" ");
				for (j = 0; j < (((number>>1)-i)<<1)-1; j++)
					printf("*");
				printf("\n");
			}
	return 0;
}
