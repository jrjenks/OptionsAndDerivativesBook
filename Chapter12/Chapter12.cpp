// Chapter12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BlackScholesMethod.h"

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;

void test_bsmethod()
{
	auto strike = 5.0;
	auto intRate = 0.03;
	auto sigma = 0.50;
	auto t1 = 1.0;
	auto numSteps = 11;
	auto numDays = 29;
	auto maxPrice = 10.0;

	BlackScholesMethod blackScholes(t1, maxPrice, strike, intRate);
	vector<double> u = blackScholes.solve(sigma, numSteps, numDays);

	double minPrice = .0;
	for (int i = 0; i < numSteps - 1; i++)
	{
		double s = ((numSteps - i - 2) * minPrice + (i + 1)*maxPrice) / (double)(numSteps - 1);
		cout << "  " << s << "  " << u[i + numDays * (numSteps - 1)] << endl;
	}
}

int main()
{
	test_bsmethod();
    return 0;
}

