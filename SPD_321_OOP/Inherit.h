#pragma once
#include<iostream>


using namespace std;

class Human
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


class WiFi : public Adapter
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

class LAN : public Adapter
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
	Router(int id, int idLAN, int idWiFi): id(id), LAN(idLAN), WiFi(idWiFi)
	{

	}
};