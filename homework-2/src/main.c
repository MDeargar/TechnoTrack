#include <stdio.h>
#include <stdlib.h>
#include "square_equation.h"

int ReadData(double* a, double* b, double* c) {
	return scanf("%lf %lf %lf", a, b, c);
}

int SolveSquare(double, double, double, double*, double*);

int main(int argc, char* argv[]) {
	double a = 0;
	double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;

	if (ReadData(&a, &b, &c) != 3) {
		printf("Incorrect input\n");
		return 0;
	}

	int number_of_solutions = SolveSquare(a, b, c, &x1, &x2);
	if (number_of_solutions == 0) {
		printf("There is no solutions\n");
	} else if (number_of_solutions == 1) {
		printf("There is one solution: %lf", x1);
	} else if (number_of_solutions == 2) {
		printf("There is twosolutions: %lf %lf", x1, x2);
	} else if (number_of_solutions == INF) {
		printf("There are infinity solutions");
	} else {
		printf("Oops. Something went wrong.");
	}

	return 0;
}