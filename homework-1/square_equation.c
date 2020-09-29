#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF -1

int Equal(double a, double b) {
	return fabs(a - b) < 1e-7;
}

/*!
 *	\brief Функция, решающая квадратное уравнение
 *	Функция, решающая квадратное уравнение с вещественными коэффициентами.
 *	\param[out] x1 В x1 записывается наименьшее из решений (если оно существует)
 *	\param[out] x2 В x2 записывается второе по величине решение (если существует)
 *	\param[in] a Старший коэффициент квадратного уравнения (при x^2)
 *	\param[in] b Коэффициент при переменной x
 *	\param[in] c Свободный член
 *	\return Количество различных решений уравнения. Если решений бесконечно, то возвращается дефайн INF. Если хотя бы один из указателей x1, x2 равено нулю, или указатели ссылаются на одну область памяти, то возвращается 0.
 */

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