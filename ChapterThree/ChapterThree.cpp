// ChapterThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::string;

int main()
{
	Date d(2015, 9, 12);
	DayOfTheWeek wd = d.dayOfTheWeek();
	cout << " day of the week: " << wd << " " << d.dayOfWeek() << endl;
	d.print();

	d.add(25);
	d.print();

	d.addTradingDays(120);
	d.print();
	cout << " day of the week: " << d.dayOfTheWeek() << " " << d.dayOfWeek() << endl;

	return 0;
}

