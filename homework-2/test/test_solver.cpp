#include "gtest/gtest.h"

#include "square_equation.h"

TEST(square_equation_two_solution, ok) {
	double a = 1.0;
	double b = -3.0;
	double c = 2.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), 2);
	ASSERT_EQ(Equal(x1, 1.0), 1);
	ASSERT_EQ(Equal(x2, 2.0), 1);
}

TEST(square_equation_one_solution, ok) {
	double a = 1.0;
	double b = -4.0;
	double c = 4.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), 1);
	ASSERT_EQ(Equal(x1, 2.0), 1);
}

TEST(square_equation_no_solution, ok) {
	double a = 1.0;
	double b = 2.0;
	double c = 5.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), 0);
}

TEST(linear_equation, ok) {
	double a = 0.0;
	double b = -3.0;
	double c = 4.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), 1);
	ASSERT_EQ(Equal(x1, -c / b), 1);
}

TEST(no_solutions, ok) {
	double a = 0.0;
	double b = 0.0;
	double c = 1.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), 0);
}

TEST(infinity_solutions, ok) {
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double x1;
	double x2;

	ASSERT_EQ(SolveSquare(a, b, c, &x1, &x2), INF);
}