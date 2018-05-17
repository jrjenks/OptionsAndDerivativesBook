#include "stdafx.h"
#include "PolynomialFunction.h"


PolynomialFunction::PolynomialFunction(const std::vector<double> &coef)
	: m_coefficients(coef)
{
}

PolynomialFunction::PolynomialFunction(const PolynomialFunction &p)
	: m_coefficients(p.m_coefficients)
{
}

PolynomialFunction::~PolynomialFunction()
{
}

PolynomialFunction &PolynomialFunction::operator=(const PolynomialFunction &p)
{
	if (this != &p)
	{
		m_coefficients = p.m_coefficients;
	}
	return *this;
}

// Use Horner's method
double PolynomialFunction::operator()(double x)
{
	int n = (int)m_coefficients.size();
	double y = 0;
	int i;
	for (i = 0; i<n - 1; ++i)
	{
		y += m_coefficients[i];
		y *= x;
	}
	if (i < n) {
		y += m_coefficients[i];
	}
	return y;
}