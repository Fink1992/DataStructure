#include <stdio.h>
#include <string.h>
void substring(char [], char []);

int main(void)
{
	char s[] = "This is a bookis";
	char t[] = "is";
	printf("parent: %s\n", s);
	printf("child: %s\n", t);
	substring(s, t);
	return 0;
}

void substring(char s[], char t[])
{
	int i, j;

	for (i = 0; i < strlen(s); i++) {
		while ((s[i+j] == t[j]) != '\0')
			j++;
		if (t[j] == '\0')
			printf("potision: %d\n", i);
		j = 0;	
	}
}
