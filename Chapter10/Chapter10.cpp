// Chapter10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "PolynomialFunction.h"
#include "SampleFunction.h"
#include "Derivative.h"
#include "NewtonMethod.h"
#include "SampleFunc.h"
#include "SimpsonsIntegration.h"

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

int test_newton_method()
{
	SampleFunction f;
	Derivative df;
	NewtonMethod nm(f, df);
	cout << " the root of the function is " << nm.getFunctionRoot(100) << endl;
	return 0;
}

int test_simpsons_integration()
{
	SampleFunc f;
	SimpsonsIntegration si(f);
	si.setNumIntervals(200);
	double integral = si.getIntegral(0.5, 2.5);
	cout << " the integral of the function is " << integral << endl;

	si.setNumIntervals(200);
	integral = si.getIntegral(0.5, 2.5);
	cout << " the integral of the function with 200 intervals is " << integral << endl;
	return 0;
}

int main()
{
	test_poly_function();
	test_newton_method();
	test_simpsons_integration();

    return 0;
}

