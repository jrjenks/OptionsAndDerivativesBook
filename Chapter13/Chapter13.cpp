// Chapter13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RandomWalkModel.h"

#include <cstdlib>
#include <iostream>
#include <random>

using std::vector;
using std::cout;
using std::endl;

int test_random_walk()
{
	RandomWalkModel rw(200, 30, 0.01);
	vector<double> walk = rw.getWalk();
	for (int i = 0; i<walk.size(); ++i)
	{
		cout << ", " << walk[i];
	}
	cout << endl;
	return 0;
}

int main()
{
	test_random_walk();
    return 0;
}

