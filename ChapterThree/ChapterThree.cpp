// ChapterThree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include "DateCompact.h"
#include "StringProduction.h"
#include "Dictionary.h"

#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::string;

void testDate()
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
}

void testDateCompact()
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
}

void testStringProduction(const char* srcPtr, const char* destPtr)
{
	string src(srcPtr);
	string dest(destPtr);

	Dictionary dic(3);
	dic.addElement("lob");
	dic.addElement("dag");
	dic.addElement("log");
	dic.addElement("car");
	dic.addElement("dog");
	dic.addElement("cat");
	dic.addElement("cob");
	dic.addElement("cab");
	dic.addElement("cag");

	dic.buildAdjancencyMatrix();

	vector<string> path;
	StringProduction sp(dic);
	if (sp.produces(src, dest, path)) {
		cout << " -- the first string produces the second" << endl;
		cout << " -- that path has size " << path.size() << ":\n";
		for (unsigned i = 0; i<path.size(); ++i) {
			cout << path[i] << "; ";
		}
	}
	else {
		cout << " the second string does not produce the second" << endl;
	}
}

int main()
{
	testDate();
	testDateCompact();
	testStringProduction("cat", "dog");

	return 0;
}