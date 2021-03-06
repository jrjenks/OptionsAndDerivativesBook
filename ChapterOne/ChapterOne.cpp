// ChapterOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GenericOption.h"

using namespace std;

int main()
{
	GenericOption option(100.0, OptionType_Put, 1.1);
	double price1 = 120.0;
	double value = option.valueAtExpiration(price1);
	cout << " For 100PUT, value at expiration for price "
		<< price1
		<< " is "
		<< value << endl;
	double price2 = 85.0;
	value = option.valueAtExpiration(85.0);
	cout << " For 100PUT, value at expiration for price "
		<< price2
		<< " is "
		<< value << endl;

	// test profitAtExpiration
	auto limit = 120.0;
	for (auto price = 80.0; price <= limit; price += 0.1)
	{
		value = option.profitAtExpiration(price);
		cout << price << ", " << value << endl;
	}

	return 0;
}
