#pragma once
#include<iostream>

using namespace std;

//class Human
//{
//	const int id;
//	char* name; 
//	int age;
//	static int count;
//
//public:
//
//	Human() :Human(0) {}
//
//	/*explicit */Human(int id) : Human("No name", 0, id)
//	{
//		//cout << "Constructor" << endl;
//		//count++;
//	}
//
//	Human(const char* n, int a, int id) : id{id}
//	{
//		setAge(a);
//		setName(n);
//		cout << "Constructor 2" << endl;
//		count++;
//	}
//
//	~Human()
//	{
//		//delete name;
//		cout << "Destructor" << endl;
//		count--;
//	}
//
//	Human& operator=(const Human& obj)
//	{
//		return *this;
//	}
//
//	Human& operator=(int a)
//	{
//		return *this;
//	}
//
//
//
//	void setName(const char* name)
//	{
//		this->name = new char[strlen(name) + 1];
//		strcpy_s(this->name, strlen(name) + 1, name);
//	}
//
//	char* getName() const
//	{
//		return name;
//	}
//
//	void setAge(int a)
//	{
//		if (a > 100 or a < 18)
//			return;
//		age = a;
//	}
//
//	int getAge() const
//	{
//		return age;
//	}
//
//	void print() const
//	{
//		cout << "Name : " << name << endl;
//		cout << "Age  : " << age << endl;
//	}
//
//	static int getCount()
//	{
//		return count;
//	}
//
//	Human copy()
//	{
//		return *this;
//	}
//
//	int getID()
//	{
//		return id;
//	}
//
//	void save(ofstream& out)
//	{
//		out << name << endl;
//		out << age << endl;
//		out << id << endl;
//	}
//};
//
//
//int Human::count = 0;