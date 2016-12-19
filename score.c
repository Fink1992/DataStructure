#include <stdio.h>

#define GRADE 3
#define CLASS 5
#define SUBJECT 2

void avg(int [][CLASS][SUBJECT]);

int main(void)
{
	int score[GRADE][CLASS][SUBJECT] = {
		{{90, 100}, {95, 100}, {90, 91}, {90, 96}, {100, 90}},
		{{90, 100}, {93, 100}, {90, 92}, {90, 97}, {100, 90}},
		{{90, 100}, {91, 100}, {90, 93}, {90, 98}, {100, 90}}};
	avg(score);	
	return 0;
}

void avg(int score[][CLASS][SUBJECT])
{
	int i, j, chi[GRADE] = {0}, eng[GRADE] = {0};

	for (i = 0; i < GRADE; i++) {
		for (j = 0; j < CLASS; j++) {
			chi[i] += score[i][j][0];
			eng[i] += score[i][j][1];
		}
	}

	for (i = 0; i < GRADE; i++) {
		printf("The AVG Chinese of Grade %d: %.6f\n", i + 1, (float)chi[i] / 5.0);
		printf("The AVG English of Grade %d: %.6f\n", i + 1, (float)eng[i] / 5.0);
	}	
}
