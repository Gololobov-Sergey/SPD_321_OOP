#pragma once
#include<iostream>


using namespace std;

class Human
{
	string name;
	int age;

public:
	Human() {}

	Human(string n, int a) :name(n), age(a) {}

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
		
	}

};


