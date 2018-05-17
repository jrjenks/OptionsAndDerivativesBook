#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class MathFunction {
public:

	virtual ~MathFunction() {}
	virtual double operator()(double x) = 0;
private:
	// this just an interface
};