#include "stdafx.h"
#include "SimpsonsIntegration.h"
#include "MathFunction.h"

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

namespace {
	const int DEFAULT_NUM_INTERVALS = 100;
}

SimpsonsIntegration::SimpsonsIntegration(MathFunction &f)
	: m_f(f),
	m_numIntervals(DEFAULT_NUM_INTERVALS)
{
}

SimpsonsIntegration::SimpsonsIntegration(const SimpsonsIntegration &p)
	: m_f(p.m_f),
	m_numIntervals(p.m_numIntervals)
{
}

SimpsonsIntegration::~SimpsonsIntegration()
{
}

SimpsonsIntegration &SimpsonsIntegration::operator=(const SimpsonsIntegration &p)
{
	if (this != &p)
	{
		m_f = p.m_f;
		m_numIntervals = p.m_numIntervals;
	}
	return *this;
}

double SimpsonsIntegration::getIntegral(double a, double b)
{
	double S = 0;
	double intSize = (b - a) / m_numIntervals;
	double x = a;

	for (int i = 0; i<m_numIntervals; ++i)
	{
		S += (intSize / 6) * (m_f(x) + m_f(x + intSize) + 4 * m_f((x + x + intSize) / 2));
		x += intSize;
	}
	return S;
}

void SimpsonsIntegration::setNumIntervals(int n)
{
	m_numIntervals = n;
}