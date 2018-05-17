#pragma once
#include "SampleFunction.h"

class Derivative : public MathFunction {
public:
	virtual ~Derivative();
	virtual double operator()(double value);
};