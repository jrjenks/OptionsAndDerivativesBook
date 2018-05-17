#pragma once

#include "MathFunction.h"

class SampleFunc : public MathFunction
{
public:
	~SampleFunc();
	double operator()(double x);
};
