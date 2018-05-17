#pragma once
//
//  Polynomial has the form  c_1 x^n + c_2 x^n-1 + ....  + c_n-1 x^1 + c_n
//

#include "MathFunction.h"

class PolynomialFunction : public MathFunction {
public:
	PolynomialFunction(const std::vector<double> &coef);
	PolynomialFunction(const PolynomialFunction &p);
	virtual ~PolynomialFunction();
	virtual PolynomialFunction &operator=(const PolynomialFunction &p);

	virtual double operator()(double x) override;
private:
	std::vector<double> m_coefficients;
};