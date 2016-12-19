#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
void sum_iter(int);
int sum_rec(int);

int main(void)
{
	int number;
	do {
	printf("Input a number:");
	scanf("%d", &number);
	if (number < 1)
		printf("%d is smaller than 1\n", number);
	else
		break;
	} while (1);
	sum_iter(number);
	return 0;
}

void sum_iter(int n)
{
	int i, sum = 0;
	char s[MAXSIZE];	/* Doesn't need to initialization ? */
	char buff[10];
	for (i = 0; i < n; i++) {
		sum += i + 1;
		if (i != 0) {
			if(strlen(s) < MAXSIZE)
				strcat(s, "+");
			else {
				printf("error: input + failed. s full\n");
				break;
			}
		}
		if (strlen(s) < MAXSIZE) {
			sprintf(buff, "%d", i + 1);
			strcat(s, buff);	
		} else {
			printf("error: s full\n");
			break;
		}
		printf("%s=%d\n", s, sum);
	}
}

void sum_rec(int n)
{

}
