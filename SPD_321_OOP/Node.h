#pragma once


template<class T>
struct Node
{
	T value;
	Node* next;

	Node(const T& value) : value(value), next(nullptr) {}
};


template<class T, class TPri = int>
struct NodeP
{
	T value;
	NodeP* next;
	TPri priority;

	NodeP(const T& value, const TPri& priority) : 
		value(value), priority(priority), next(nullptr) {}
};