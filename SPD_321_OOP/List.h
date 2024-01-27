#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"

using namespace std;

template<class T>
class List
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t   size = 0;

	Node<T>* getNode(size_t index) const;

public:
	List();
	List(initializer_list<T> list);
	~List();
	List(const List<T>& fl);
	List<T>& operator=(const List<T>& fl);
	List<T> operator+(const List<T>& fl);
	void operator+=(const List<T>& fl);

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

	size_t find(const T& value);
};

template<class T>
Node<T>* List<T>::getNode(size_t index) const
{
	Node<T>* pos;
	if (index < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < index; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - index - 1; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List()
{
}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->push_back(elem);
	}
}

template<class T>
List<T>::~List()
{
	this->clear();
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		first->prev = new Node<T>(value);
		first->prev->next = first;
		first = first->prev;
	}
	size++;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}

	if (index == 0)
	{
		this->push_front(value);
	}
	else if(index == size)
	{
		this->push_back(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* pos = this->getNode(index);
		newNode->next = pos;
		newNode->prev = pos->prev;
		newNode->prev->next = newNode;
		pos->prev = newNode;
		size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = nullptr;
	}
	size--;
}

template<class T>
void List<T>::pop_back()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
	size--;
}

template<class T>
void List<T>::clear()
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
void List<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
