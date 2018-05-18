#pragma once

#include "BinomialModel.h"

class AmericanBinomialModel : public BinomialModel {
	AmericanBinomialModel(const BinomialModel &p);
	~AmericanBinomialModel();
	AmericanBinomialModel &operator=(const BinomialModel &p);

	AmericanBinomialModel(double T, // expiration time
		double S,   // stock price
		double r,   // interest rate
		double sigma,
		double q,   // dividend yield
		int n,      // number of steps
		bool call
	);

	virtual void computePriceStep(int i, int j, double K, vec &prices,
		double p_u, double p_d, double u);
};

