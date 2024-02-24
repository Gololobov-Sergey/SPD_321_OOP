#pragma once
#include<iostream>


using namespace std;

class IInfo
{
public:
	virtual void info() = 0;
};


class Animal : public IInfo
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

	virtual string getType() const
	{
		return "Animal";
	}

	virtual string voice() = 0;
};

string Animal::voice()
{
	return "No say";
}



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

	virtual string getType() const override /*final*/
	{
		return "Cat";
	}

	virtual string voice() override
	{
		return "Maw Maw";
	}

	void info() override
	{
		cout << "I`m Cat - " << voice() << endl;
	}
};

class SiamCat : public Cat
{
public:
	SiamCat(string n, int a) : Cat(n, a)
	{

	}

	virtual string getType() const override
	{
		return "SiamCat";
	}

	virtual string voice() override
	{
		return "Myaw Myaw";
	}

	void info() override
	{
		cout << "I`m SiamCat - " << voice() << endl;
	}
};

class SiamCat2 : public SiamCat
{
public:
	SiamCat2(string n, int a) : SiamCat(n, a)
	{

	}

	virtual string getType() const override
	{
		return "SiamCat";
	}

	void info() override
	{
		cout << "I`m SiamCat2 - " << voice() << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a)
	{

	}

	virtual string getType() const override
	{
		return "Dog";
	}

	virtual string voice() override
	{
		return "Gaw Gaw";
	}

	void info() override
	{
		cout << "I`m Dog - " << voice() << endl;
	}
};


class Ravlik : public Animal 
{
public:
	Ravlik(string n, int a) : Animal(n, a)
	{

	}

	virtual string getType() const override
	{
		return "Ravlik";
	}

	virtual string voice() override
	{
		return Animal::voice();
	}

	void info() override
	{
		cout << "I`m Ravlik - " << voice() << endl;
	}
};


class Fish : public Animal
{
public:
	Fish(string n, int a) : Animal(n, a)
	{

	}

	virtual string getType() const override
	{
		return "Fish";
	}

	virtual string voice() override
	{
		return Animal::voice();
	}

	void info() override
	{
		cout << "I`m Fish - " << voice() << endl;
	}
};