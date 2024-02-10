#pragma once
#include<iostream>


using namespace std;

namespace C
{
	class Engine
	{

	public:
		void start()
		{
			cout << "Start Engine" << endl;
		}
	};

	class Car
	{
		Engine* engine;

	public:

		Car()
		{
			engine = new Engine;
		}

		~Car()
		{
			delete engine;
		}

		void move()
		{
			engine->start();
			cout << "Car move" << endl;
		}
	};
}


namespace A
{
	class Engine
	{

	public:

		int power = 10;

		void start()
		{
			cout << "Start Engine" << endl;
		}

		void setPower()
		{
			power += 5;
		}
	};

	class Car
	{
		Engine* engine = nullptr;

	public:

		Car(Engine* en) : engine(en) {}


		void move()
		{
			engine->start();
			cout << "Car move" << endl;
		}

		Engine* getEngine()
		{
			return engine;
		}

		void info()
		{
			cout << "Power: " << engine->power << endl;
		}
	};

	class STO
	{
		Engine* engine;

	public:
		void setEngine(Engine* en)
		{
			engine = en;
		}

		void test()
		{
			if (engine)
			{
				engine->setPower();
			}
		}
	};
}


