#pragma once
//
// a Newton method implementation.
//

#include "MathFunction.h"

class NewtonMethod {
public:
	// Takes as parameter the function and its derivatives
	//
	NewtonMethod(MathFunction &f, MathFunction &derivative);
	NewtonMethod(MathFunction &f, MathFunction &derivative, double error);
	NewtonMethod(const NewtonMethod &p);
	virtual ~NewtonMethod();
	NewtonMethod &operator=(const NewtonMethod &p);

	double getFunctionRoot(double initialValue);
private:
	MathFunction & m_f;
	MathFunction &m_derivative;
	double m_error;
};
