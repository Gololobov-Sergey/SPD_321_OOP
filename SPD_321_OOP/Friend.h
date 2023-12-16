#pragma once
#include<iostream>

using namespace std;

class Humidity;
class Temperature;

class WeatherInformer
{
public:
	void info(const Temperature& t, const Humidity& h);
};

class Temperature
{
	int temp;

public:
	Temperature(int t) :temp(t) {}

	//friend void info(const Temperature& t, const Humidity& h);
	
	friend void WeatherInformer::info(const Temperature& t, const Humidity& h);

	//friend class WeatherInformer;

	void print() const {}
};


class Humidity
{
	int humidity;

public:
	Humidity(int h) :humidity(h) {}

	//friend void info(const Temperature& t, const Humidity& h);
	friend void WeatherInformer::info(const Temperature& t, const Humidity& h);
	//friend class WeatherInformer;
};


//void info(const Temperature& t, const Humidity& h)
//{
//	cout << "Temp     : " << t.temp << " " << (char)248 << "C" << endl;
//	cout << "Humidity : " << h.humidity << " %" << endl;
//}

void WeatherInformer::info(const Temperature& t, const Humidity& h)
{
	cout << "Temp     : " << t.temp << " " << (char)248 << "C" << endl;
	cout << "Humidity : " << h.humidity << " %" << endl;
}

