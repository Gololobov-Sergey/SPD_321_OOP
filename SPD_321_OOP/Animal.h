#pragma once
#include<iostream>


using namespace std;


class Animal
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a)
	{

	}

	virtual ~Animal()
	{
		cout << "Des Animal" << endl;
	}

	virtual string getType()
	{
		return "Animal";
	}
};


class Cat /*final*/: public Animal
{
public:
	Cat(string n, int a) : Animal(n, a)
	{

	}

	~Cat()
	{
		cout << "Des Cat" << endl;
	}

	virtual string getType() override /*final*/
	{
		return "Cat";
	}
};

class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a)
	{

	}

	virtual string getType() override
	{
		return "SiamCat";
	}
};

class SiamCat2 : public SiamCat
{
public:
	SiamCat2(string n, int a) : SiamCat(n, a)
	{

	}

	virtual string getType() override
	{
		return "SiamCat";
	}
};

class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a)
	{

	}

	virtual string getType() override
	{
		return "Dog";
	}
};
