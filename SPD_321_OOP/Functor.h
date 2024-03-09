#pragma once
#include<limits.h>

using namespace std;

class ContainerInfo
{
	int even = 0;
	int odd = 0;
	int sum = 0;
	int min = INT_MAX;
	int max = INT_MIN;

public:
	void operator()(int value)
	{
		if (value % 2 == 0)
			even++;
		else
			odd++;

		if (value > max)
			max = value;

		if (value < min)
			min = value;

		sum += value;
	}

	void clear()
	{
		even = 0;
		odd = 0;
		sum = 0;
		min = INT_MAX;
		max = INT_MIN;
	}

	int getEvenCount()
	{
		return even;
	}



};
