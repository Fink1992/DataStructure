#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 100
#define BUFSIZE 100
#define VALSIZE 100
#define NUMBER '0'
int getop(char*);
int getch(void);
void ungetch(int);
void push(int);
int pop(void);
int cal(int ,int, int);

int buf[BUFSIZE];
int val[MAXVAL];
int bufp = 0;
int sp = 0;

int main(void)
{
	char s[MAXOP];
	int type, num1, num2, c;
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				printf("%s", s);
				if ((c = pop())) {
					num2 = atoi(s);
					num1 = cal(num1, num2, c);
				} else
					num1 = atoi(s);
				break;
			case '+': case '-': case '*': case '/':
				printf("%c", type);
				push(type);
				break;
			case '\n':
				printf("=%d\n", num1);
				break;
			default:
				printf("error: undefined behavior\n");
				break;
		}
	}
	return 0;	
}

int getop(char *s)
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c))
		return c;
	i = 0;
	while (isdigit(s[++i] = c = getch()))
		;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: buf full\n");	
}

void push(int c)
{
	if (sp < VALSIZE)
		val[sp++] = c;
	else
		printf("error: val full\n");
}

int pop(void)
{
	return (sp > 0) ? val[--sp] : 0;
}

int cal(int num1, int num2, int op)
{
	switch (op) {
		case '+':
			return num1 + num2;
		case '*':
			return num1 * num2;
		case '-':
			return num1 - num2;
		case '/':
			if (num2)
				return num1/num2;
			printf("error: zero divided\n");
			return 0;
		default:
			printf("error: unknown command %c\n", op);
			return 0;
	}
}
