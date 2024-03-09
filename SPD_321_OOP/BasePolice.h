#pragma once
#include<iostream>
#include"BTree.h"
#include"List.h"
#include"Menu.h"

using namespace std;

class Protocol
{
	string numTZ;
	string date;
	string info;
	int sum;
	bool isPay = false;

public:
	string getNumTZ() { return numTZ; }
	friend ostream& operator<<(ostream& out, const Protocol& p);
	friend istream& operator>>(istream& in, const Protocol& p);
};

inline ostream& operator<<(ostream& out, const Protocol& p)
{
	return out;
}

istream& operator>>(istream& in, const Protocol& p)
{
	return in;
}

class BasePolice
{
	BTree<string, List<Protocol>> base;

	void addProtocol();
	void printAll();
	void printTZ();
	void printDiapazon();
	void save();
	void load();
	void pay();


public:
	
	void menu();
};

void BasePolice::menu()
{
	load();
	/*do
	{
		system("cls");
		int c = Menu::select_vertical({ 
			"Add", 
			"Print all", 
			"Print TZ", 
			"Print Diap", 
			"Pay", 
			"Exit" },
			HorizontalAlignment::Left, 1);
		switch (c)
		{
		case 0: addProtocol(); break;
		case 1: addProtocol(); break;
		case 2: addProtocol(); break;
		case 3: addProtocol(); break;
		case 4: addProtocol(); break;
		case 5: save();  exit(0);
		}

	} while (true);*/
}
void BasePolice::addProtocol()
{
	system("cls");
	cout << "Add protocol" << endl;
	cout << "--------------------" << endl;
	Protocol p;
	cin >> p;
	List<Protocol>* list = base.getValue(p.getNumTZ());
	if (list)
	{
		list->push_back(p);
	}
	else
	{
		List<Protocol> newList;
		newList.push_back(p);
		base.push_r(p.getNumTZ(), newList);
	}
}

inline void BasePolice::save()
{
}

inline void BasePolice::load()
{
}