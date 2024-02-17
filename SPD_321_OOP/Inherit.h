#pragma once
#include<iostream>
#include"Animal.h"


using namespace std;

class Human : public IInfo
{
	string name;
	int age;

protected:
	int number;

public:
	Human() {}

	Human(string n, int a) :name(n), age(a) {}

	string getName() 
	{
		return name;
	}

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Age : " << age << endl;
	}
};


class FootballPlayer : public Human
{
	int games;

public:
	FootballPlayer(string n, int a, int g) : Human(n, a), games(g)
	{
		number = 100;
	}

	string getName() = delete;

	void print()
	{
		Human::print();
		cout << "Games : " << games << endl;
	}

	void info() override
	{
		Human::print();
		cout << "Games : " << games << endl;
	}
};


class AA
{
private:
	int a1;

protected:
	int a2;

public:
	int a3;
};


class BB : private AA
{
private:
	int b1;

protected:
	int b2;

public:
	int b3;

	void info()
	{
		a3;
	}
};

class CC : public BB
{
public:
	void info()
	{
		b3;
	}
};


class Adapter
{
public:
	int a;
};


class WiFi : virtual public Adapter
{
	int id;

public:
	WiFi(int id): id(id)
	{

	}

	int getID()
	{
		return id;
	}
};

class LAN : virtual public Adapter
{
	int id;

public:
	LAN(int id) : id(id)
	{

	}

	int getID()
	{
		return id;
	}
};

class Router : public LAN, public WiFi
{
	int id;

public:
	Router(int id, int idLAN, int idWiFi): 
		id(id), LAN(idLAN), WiFi(idWiFi), Adapter()
	{

	}
};



class ILogError
{
public:
	virtual~ILogError() {}
	virtual void writeError(string error) = 0;
};

class FileLogError : public ILogError
{
	string path;

public:

	FileLogError(string path) : path(path)
	{

	}

	virtual void writeError(string error) override
	{
		ofstream out(path, ios::app);
		out << error << endl;
		out.close();
	}

};

class ConsoleLogError : public ILogError
{

public:

	ConsoleLogError() { }

	virtual void writeError(string error) override
	{
		cout << error << endl;
	}
};