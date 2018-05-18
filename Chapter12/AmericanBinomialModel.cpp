#include "stdafx.h"
#include "AmericanBinomialModel.h"

AmericanBinomialModel::AmericanBinomialModel(const BinomialModel &p)
	: BinomialModel(p)
{
}

AmericanBinomialModel::~AmericanBinomialModel()
{
}

AmericanBinomialModel &AmericanBinomialModel::operator=(const BinomialModel &p)
{
	BinomialModel::operator=(p);  // no new data members in this class
	return *this;
}

AmericanBinomialModel::AmericanBinomialModel(double T, // expiration time
	double S,   // stock price
	double r,   // interest rate
	double sigma,
	double q,   // dividend yield
	int n,      // number of steps
	bool call)
	: BinomialModel(T, S, r, sigma, q, n, call)
{
}

void AmericanBinomialModel::computePriceStep(int i, int j, double K, vec &prices, double p_u, double p_d, double u)
{
	BinomialModel::computePriceStep(i, j, K, prices, p_u, p_d, u);

	// compute exercise price for American option
	//
	double exercise = K - getStockPrice() * pow(u, 2 * i - j);
	if (prices[i] < exercise)
	{
		prices[i] = exercise;
	}
}