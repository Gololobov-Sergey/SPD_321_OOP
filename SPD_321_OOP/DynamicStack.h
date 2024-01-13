#pragma once

#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

using namespace std;

template<class T, size_t limit>
class DStack
{
	T* data;
	size_t size;

public:
	DStack();
	DStack(initializer_list<T> list);

	~DStack();
	DStack(const DStack<T>& obj);
	DStack<T>& operator=(const DStack<T>& obj);

	void push(const T& value);
	const T& peek() const;
	void pop();
	bool isEmpty() const;
	size_t length() const;
	void clear();

	void print() const;
};
