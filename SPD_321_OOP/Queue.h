#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"
#include"Class.h"

using namespace std;

template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

public:
	Queue();
	Queue(initializer_list<T> list);
	~Queue();
	Queue(const Queue<T>& q);
	Queue<T>& operator=(const Queue<T>& q);
	void enqueue(const T& value);
	void dequeue();
	T& peek() const;
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;

	void ring();

};

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T>
Queue<T>::~Queue()
{
	this->clear();
}

template<class T>
void Queue<T>::enqueue(const T& value)
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
void Queue<T>::dequeue()
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
T& Queue<T>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
size_t Queue<T>::length() const
{
	return size;
}

template<class T>
void Queue<T>::clear()
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
void Queue<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		//temp->value.print();
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::ring()
{
	/*this->enqueue(first->value);
	this->dequeue();*/

	Node<T>* temp = first;
	first = first->next;
	last->next = temp;
	last = temp;
	last->next = nullptr;
}

////////////////////////////////
//                            //
/////// PriorityQueue  /////////
//                            //
////////////////////////////////

template<class T, class TPri = int>
class PriorityQueue
{
	NodeP<T, TPri>* first = nullptr;
	NodeP<T, TPri>* last = nullptr;
	size_t   size = 0;

public:
	PriorityQueue();
	PriorityQueue(initializer_list<T> list);
	~PriorityQueue();
	PriorityQueue(const PriorityQueue<T, TPri>& q);
	PriorityQueue<T, TPri>& operator=(const PriorityQueue<T, TPri>& q);
	void enqueue(const T& value, const TPri& priority);
	void dequeue();
	T& peek() const;
	bool isEmpty() const;
	size_t length() const;
	void clear();
	void print() const;

	void superMethod();

	void forEach(void(*method)(T elem));
};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
	for (T elem : list)
	{
		this->enqueue(elem, TPri());
	}
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	this->clear();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, const TPri& priority)
{
	NodeP<T, TPri>* newNode = new NodeP<T, TPri>(value, priority);
	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else
	{
		NodeP<T, TPri>* pos = first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	NodeP<T, TPri>* temp = first;
	first = first->next;
	delete temp;
	size--;
	last = (size == 0) ? nullptr : last;

}

template<class T, class TPri>
inline T& PriorityQueue<T, TPri>::peek() const
{
	assert(size > 0);
	return first->value;
}

template<class T, class TPri>
bool PriorityQueue<T, TPri>::isEmpty() const
{
	return size == 0;
}

template<class T, class TPri>
size_t PriorityQueue<T, TPri>::length() const
{
	return size;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	NodeP<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print() const
{
	NodeP<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::superMethod()
{
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::forEach(void(*method)(T elem))
{
	NodeP<T, TPri>* temp = first;
	while (temp)
	{
		method(temp->value);
		temp = temp->next;
	}
}

template<>
void PriorityQueue<Human, int>::superMethod()
{
	NodeP<Human, int>* temp = first;
	while (temp)
	{
		temp->value.setAge(temp->value.getAge() + 1);
		temp = temp->next;
	}
}
