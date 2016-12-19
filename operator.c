#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100
#define MAXSIZE 100
#define VALSIZE 100
#define NUMBER '0'
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
char buf[BUFSIZE];
int bufp = 0;
char val[MAXSIZE];
int sp = 0;

int main(void)
{
	char s[MAXSIZE];
	int op, op2;

	while ((op = getop(s)) > 0) {
		switch (op) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
			case '-':
				if (!(op2 = pop())) {
					push(pop() / op2);	
				} else 
					printf("error: zero divided\n");
				break;
			case '/':
				if (!(op2 = pop()))
					push(pop() / op2);
				else
					printf("error: zero divided\n");
				break;	
			case '\n':
				printf("%8.1g\n", pop());
				break;
		}
	}
}

int getop(char s[])
{
	int i = 0, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;	
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(c = getch()))
			s[++i] = c;
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

void push(double i)
{
	if (sp < MAXSIZE)
		val[sp++] = i;
	else
		printf("error: val full\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	printf("error: val empty\n");
	return 0.0;
}

int getch(void)
{
	return (bufp >0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: buf full\n");
}

