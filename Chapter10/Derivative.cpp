#include "stdafx.h"
#include "Derivative.h"

Derivative::~Derivative()
{
}

double Derivative::operator ()(double x)
{
	return 3 * (x - 1)*(x - 1);
}
