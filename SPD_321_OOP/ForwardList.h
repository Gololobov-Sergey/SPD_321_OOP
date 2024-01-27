#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

using namespace std;

template<class T>
class ForwardList
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

	Node<T>* getNode(size_t index) const;

public:
	ForwardList();
	ForwardList(initializer_list<T> list);
	~ForwardList();
	ForwardList(const ForwardList<T>& fl);
	ForwardList<T>& operator=(const ForwardList<T>& fl);
	ForwardList<T> operator+(const ForwardList<T>& fl);
	void operator+=(const ForwardList<T>& fl);

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);

	T& front() const;
	T& back() const;
	T& at(size_t index) const;

	T& operator[](size_t index) const;

	void clear();
	size_t length() const;
	void print() const;

	void sort() const;

};

template<class T>
Node<T>* ForwardList<T>::getNode(size_t index) const
{
	Node<T>* pos = first;
	for (size_t i = 0; i < index; i++)
	{
		pos = pos->next;
	}
	return pos;
}

template<class T>
ForwardList<T>::ForwardList()
{
}

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push_back(elem);
	}
}

template<class T>
ForwardList<T>::~ForwardList()
{
	this->clear();
}

template<class T>
void ForwardList<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
void ForwardList<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void ForwardList<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}

	if (index == 0)
	{
		this->push_front(value);
	}
	else if (index == size)
	{
		this->push_back(value);
	}
	else
	{
		Node<T>* pos = this->getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next = newNode;
		size++;
	}
}

template<class T>
void ForwardList<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;
	}
}

template<class T>
void ForwardList<T>::pop_back()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		delete last;
		first = last = nullptr;
	}
	else
	{
		last = getNode(size - 2);
		delete last->next;
		last->next = nullptr;
	}
	size--;
}

template<class T>
void ForwardList<T>::remove(size_t index)
{
	if (index >= size)
	{
		return;
	}

	if (index == 0)
	{
		this->pop_front();
	}
	else if (index == size - 1)
	{
		this->pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		size--;
	}
}

template<class T>
T& ForwardList<T>::front() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
inline T& ForwardList<T>::back() const
{
	assert(size > 0);
	return last->value;
}

template<class T>
T& ForwardList<T>::at(size_t index) const
{
	assert(index >= 0 && index < size);
	return this->getNode(index)->value;
}

template<class T>
T& ForwardList<T>::operator[](size_t index) const
{
	return this->at(index);
}

template<class T>
void ForwardList<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T>
inline size_t ForwardList<T>::length() const
{
	return size;
}

template<class T>
void ForwardList<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
