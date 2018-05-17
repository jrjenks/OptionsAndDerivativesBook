#pragma once

#include "MathFunction.h"

class SampleFunction : public MathFunction {
public:
	virtual ~SampleFunction();
	virtual double operator()(double value);
};

