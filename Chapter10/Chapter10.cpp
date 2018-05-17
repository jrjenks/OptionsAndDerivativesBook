// Chapter10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "PolynomialFunction.h"

int test_poly_function()
{
	PolynomialFunction f({ 1, 0, 0 });

	double begin = -2, end = 2;
	double step = (end - begin) / 100.0;
	for (int i = 0; i<100; ++i)
	{
		cout << begin + step * i << ", ";
	}
	cout << endl;
	for (int i = 0; i<100; ++i)
	{
		cout << f(begin + step * i) << ", ";
	}

	return 0;
}

int main()
{
	test_poly_function();

    return 0;
}

