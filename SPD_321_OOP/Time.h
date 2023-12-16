#pragma once
#include<iostream>

using namespace std;

class Time
{
	int hour;
	int minutes;
	int second;

public:
	Time() : Time(0) { cout << "Ctor 0" << endl; }
	Time(int h) : Time(h, 0) { cout << "Ctor 1" << endl; }
	Time(int h, int m) : Time(h, m, 0) { cout << "Ctor 2" << endl; }
	Time(int h, int m, int s) : hour(h), minutes(m), second(s) { cout << "Ctor 3" << endl; }
};

