// ChapterTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RandomWalkGenerator.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//
// This is a testing stub. It generates a sequence of random points.
//
int main()
{
	// 100 steps starting at $30
	RandomWalkGenerator rw(100, 30, 0.01);
	vector<double> walk = rw.generateWalk();

	for (int i = 0; i<walk.size(); ++i)
	{
		cout << i << ", " << walk[i] << ", " << endl;
	}
	cout << endl;
	return 0;
}
