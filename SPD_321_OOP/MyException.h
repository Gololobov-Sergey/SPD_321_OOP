#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class MyException
{
	string date;
	string time;
	string file;
	string error;
	int line;

	string path = "log_ex.txt";

protected:

	string message;

public:
	MyException(string d, string t, string f, string e, int l):
		date(d), time(t), file(f), error(e), line(l)	
	{
		message = date + " | " + time + " | " + file + " | " +
			to_string(l) + " | " + error;
	}

	void saveLog()
	{
		ofstream out(path, ios::app);
		out << message << endl;
		out.close();
	}

	string getError()
	{
		return error;
	}

	string getConsole()
	{
		return message;
	}
	
};

class MyMathException : public MyException
{
	int arg;

public:
	MyMathException(string d, string t, string f, string e, int l, int arg):
		MyException(d, t, f, e, l), arg(arg)
	{
		message += " | " + to_string(arg);
	}
};



class ExA
{
	int a;

public:
	ExA(int a) : a(a)
	{
		if (a < 0)
			throw 1;
		// code
	}
};


class ExB : public ExA
{
public:
	ExB(int a) try : ExA(a)
	{
		
	}
	catch (...)
	{
		cout << "Error A" << endl;
	}
};