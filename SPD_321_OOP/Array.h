#pragma once
#include<iostream>

using namespace std;


class Array
{
	int* arr;
	size_t size;

public:
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
	}

	~Array()
	{
		//delete[] arr;
	}

	void setRandom(int min = 0, int max = 9)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
