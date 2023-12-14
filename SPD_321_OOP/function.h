#pragma once

template< class T>
void addElem(T*& arr, int& size, T elem)
{
	T* _new = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		_new[i] = arr[i];
	}
	_new[size] = elem;
	size++;
	delete[] arr;
	arr = _new;
}
