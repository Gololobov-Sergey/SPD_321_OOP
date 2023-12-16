#pragma once
#include<iostream>

using namespace std;


class Fraction
{
	int ch;
	int zn;

public:
	Fraction() : Fraction(0) {}
	Fraction(int ch) : Fraction(ch, 1) {}
	Fraction(int ch, int zn) : ch(ch), zn(zn) {}

	void print()
	{
		cout << ch << "/" << zn << endl;
	}

	Fraction operator-(Fraction f1)
	{
		Fraction res;
		res.ch = f1.ch * zn - ch * f1.zn;
		res.zn = f1.zn * zn;
		return res;
	}

	Fraction operator-()
	{
		return Fraction(-ch, zn);
	}

	Fraction operator+(Fraction f1)
	{
		Fraction res;
		res.ch = f1.ch * zn + ch * f1.zn;
		res.zn = f1.zn * zn;
		return res;
	}

	Fraction add(Fraction f)
	{
		Fraction res;
		res.ch = ch * f.zn + f.ch * zn;
		res.zn = zn * f.zn;
		return res;
	}

	Fraction operator++() // prefix
	{
		ch += zn;
		return *this;
	}

	Fraction operator++(int) // postfix
	{
		Fraction res = *this;
		ch += zn;
		return res;
	}

	auto operator<=>(Fraction f) 
	{
		return  (float)ch / zn <=> (float)f.ch / f.zn;
	}

	bool operator!()
	{
		return !ch;
	}

	/*bool operator<(Fraction f)
	{
		return  (float)ch / zn < (float)f.ch / f.zn;
	}*/


	//friend Fraction operator+(Fraction f1, Fraction f2);
};

//Fraction operator+(Fraction f1, Fraction f2)
//{
//	Fraction res;
//	res.ch = f1.ch * f2.zn + f2.ch * f1.zn;
//	res.zn = f1.zn * f2.zn;
//	return res;
//}