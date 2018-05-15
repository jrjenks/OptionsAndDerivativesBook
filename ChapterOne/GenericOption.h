#pragma once
#include <stdio.h>

//
// option types based on direction: call or put
enum OptionType {
	OptionType_Call,
	OptionType_Put
};

//
// class the represents a generic option
//
class GenericOption {
public:
	GenericOption(double strike, OptionType type, double cost);
	GenericOption(const GenericOption &p);
	~GenericOption();
	GenericOption &operator=(const GenericOption &p);

	double valueAtExpiration(double underlyingAtExpiration);
	double profitAtExpiration(double underlyingAtExpiration);
private:
	double m_strike;
	OptionType m_type;
	double m_cost;
};