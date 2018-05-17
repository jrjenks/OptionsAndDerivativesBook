#include "stdafx.h"
#include "SampleFunc.h"

SampleFunc::~SampleFunc()
{
}

double SampleFunc::operator()(double x)
{
	return sin(x);
}
