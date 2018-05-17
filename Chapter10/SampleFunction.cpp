#include "stdafx.h"
#include "SampleFunction.h"

SampleFunction::~SampleFunction()
{
}

double SampleFunction::operator ()(double x)
{
	return (x - 1)*(x - 1)*(x - 1);
}