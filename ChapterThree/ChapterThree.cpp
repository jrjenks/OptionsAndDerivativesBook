// ChapterThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include "DateCompact.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::string;

int testDate()
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

int testDateCompact()
{
	DateCompact d(2008, 3, 17);
	DateCompact e(2008, 5, 11);
	cout << " size of DateCompact: " << sizeof(DateCompact) << endl;

	d.print();
	e.print();

	if (d < e)
	{
		cout << " d is less than e " << endl;
	}
	else
	{
		cout << " d is not less than e " << endl;
	}

	Date date(2008, 3, 17);
	cout << " size of Date: " << sizeof(Date) << endl;

	return 0;
}

int main()
{
	testDate();
	testDateCompact();

	return 0;
}