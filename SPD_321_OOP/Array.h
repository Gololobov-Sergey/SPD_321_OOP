#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class Array
{
	T* arr;
	size_t size;

public:
	explicit Array(int size)
	{
		cout << "Constructor" << endl;
		this->size = size;
		arr = new T[size];
	}

	Array(const Array& obj)
	{
		cout << "Constructor Copy" << endl;
		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~Array()
	{
		delete[] arr;
		cout << "Destructor" << endl;
	}

	Array& operator=(const Array& obj)
	{
		//1
		if (this == &obj)
			return *this;

		//2
		delete[] this->arr;

		//3
		this->size = obj.size;
		this->arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			this->arr[i] = obj.arr[i];
		}

		//4
		return *this;
	}

	void setRandom(T min = 0, T max = 9);


	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	void print2()
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i].print();
		}
		cout << endl;
	}

	T at(int index)
	{
		assert(index >= 0 || index < size);
		return arr[index];
	}

	T operator[](int index)
	{
		assert(index >= 0 || index < size);
		return arr[index];
	}

	T operator[](const char* key)
	{
		if (strcmp(key, "zero") == 0)
			return arr[0];
		if (strcmp(key, "one") == 0)
			return arr[1];
		if (strcmp(key, "two") == 0)
			return arr[2];
		if (strcmp(key, "tree") == 0)
			return arr[3];
	}

	void operator()(int newSize)
	{
		T* newArr = new T[newSize]{ 0 };
		int s = (newSize > size) ? size : newSize;
		for (size_t i = 0; i < s; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		size = newSize;
		arr = newArr;
	}
};

template<class T>
void Array<T>::setRandom(T min, T max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

template<>
void Array<float>::setRandom(float min, float max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (int)(max - min + 1) + min + 0.125f;
	}
}

//template<>
//void Array<Human>::setRandom(Human min, Human max)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		arr[i] = Human(i);
//	}
//}



template<class T, int size>
class StaticArray
{
	T arr[size];

public:

};

