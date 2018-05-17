#include "stdafx.h"
#include "NewtonMethod.h"

#include <iostream>
#include <cmath>

using std::endl;
using std::cout;

namespace {
	const double DEFAULT_ERROR = 0.0001;
}

NewtonMethod::NewtonMethod(MathFunction &f, MathFunction &derivative)
	: m_f(f),
	m_derivative(derivative),
	m_error(DEFAULT_ERROR)
{
}

NewtonMethod::NewtonMethod(MathFunction &f, MathFunction &derivative, double error)
	: m_f(f),
	m_derivative(derivative),
	m_error(error)
{
}

NewtonMethod::NewtonMethod(const NewtonMethod &p)
	: m_f(p.m_f),
	m_derivative(p.m_derivative),
	m_error(p.m_error)
{
}

NewtonMethod::~NewtonMethod()
{
}

NewtonMethod &NewtonMethod::operator=(const NewtonMethod &p)
{
	if (this != &p)
	{
		m_f = p.m_f;
		m_derivative = p.m_derivative;
		m_error = p.m_error;
	}
	return *this;
}

double NewtonMethod::getFunctionRoot(double x0)
{
	double x1 = x0;
	do
	{
		x0 = x1;
		cout << " x0 is " << x0 << endl;  // this line just for demonstration
		double d = m_derivative(x0);
		double y = m_f(x0);
		x1 = x0 - y / d;
	} while (std::abs(x0 - x1) > m_error);
	return x1;
}

