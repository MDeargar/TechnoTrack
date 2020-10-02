#include "square_equation.h"

int Equal(double a, double b) {
	return fabs(a - b) < 1e-7;
}

int SolveSquare(double a, double b, double c, double* x1, double* x2) {	
	if (x1 == 0 || x2 == 0 || x1 == x2) {
		return 0;
	}
	
	if (Equal(a, 0.0)) {
		if (Equal(b, 0.0)) {
			if (Equal(c, 0.0)) {
				return INF;
			}

			return 0;
		}

		*x1 = -c / b;
		return 1;
	}

	double D = b * b - 4 * a * c;

	if (D < 0.0) {
		return 0;
	}

	*x1 = (-b - sqrt(D)) / (2 * a);
	*x2 = (-b + sqrt(D)) / (2 * a);

	return Equal(D, 0.0) ? 1 : 2;
}