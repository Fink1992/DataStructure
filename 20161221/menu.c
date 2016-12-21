#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char **p;
	int c;
	char *menu[] = {
		"a - add new record",
		"d - delete record",
		"q - quit",
		NULL
	};

	do {
		printf("Choice: PLease select an action\n");
		p = menu;
		while (*p != NULL) {
			printf("%s\n", *p);
			p++;
		}
		while((c = getchar()) != '\n') {
		printf("You have chosen:%c\n\n", c);
		if (c == 'q')
			break;
		}
	} while (c != 'q');
	return 0;
}
