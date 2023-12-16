
#include <iostream>
#include <fstream>

#include"Class.h"
#include"Array.h"
#include"function.h"
#include"Point.h"
#include"Time.h"
#include"Friend.h"
#include"Fraction.h"

#define PI 3.141592
#define SQR(n) (n)*(n)
#define ЦИКЛ(n) for(int i = 0; i < n; i++)

#define TEST
#define SIZE 50

using namespace std;

void printArray(Array a)
{
	a.print();
}

int main()
{

	////////////////  16.12.2023  //////////////////

	// ?:  ::  .  ->  sizeof

	// =
	// -  +  ++  --
	// + - * / % += -= *= /= %=
	// !
	// == != > < >= <=
	// & | >> << ^ 
	// () [] 


	Fraction f1(3, 5);
	Fraction f2(2, 3);
	//Fraction f3 = f1.add(f2);
	Fraction f3 = ++f1;
	f3.print();
	//cout << f3 << endl;
	//float ff = f1;



	/*Array a(10);
	a.setRandom(10, 20);
	a.print();
	printArray(a);
	a.print();

	Array b(a);*/


	//Time t;


	/*Temperature t(-1);
	Humidity h(50);
	
	WeatherInformer w;
	w.info(t, h);*/

	//cout << Human::getCount() << endl;

	//{
	//	Human h(99);
	//	cout << h.getCount() << endl;
	//	h.setName("Oleg");
	//	h.setAge(20); // setAge(h)
	//	cout << h.getName() << endl;
	//	cout << h.getAge() << endl;
	//	
	//}

	//Human h2("Petro", 30, 999);
	//cout << Human::getCount() << endl;

	///*int a = 5;
	//int b(5.3);
	//int c{ (int)5.3 };*/

	//Human* h3 = new Human(33);
	//h3->getAge();


	/*Array a(10);
	a.setRandom();
	printArray(a);*/


	/*int a[] = { 1,2,3,4,5 };
	ofstream out;
	out.open("text.txt");
	for (size_t i = 0; i < 5; i++)
	{
		out << a[i] << " ";
	}
	out.close();*/

	/*int* b = nullptr;
	int size = 0;
	ifstream in("text.txt");
	int c;
	while (in >> c)
	{
		addElem(b, size, c);
	}
	in.close();

	for (size_t i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;*/



	
	
	/*ifstream in("text.txt");
	int c;
	in >> c;
	int* b = new int[c];
	for (size_t i = 0; i < c; i++)
	{
		in >> b[i];
	}
	in.close();

	for (size_t i = 0; i < c; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;*/


	//Human h[] = { Human("Petro", 30, 999), Human("Oleg", 22, 777) };
	//ofstream out("human.txt");
	//for (size_t i = 0; i < 2; i++)
	//{
	//	h[i].save(out);
	//	/*out << h[i].getName() << endl;
	//	out << h[i].getAge() << endl;
	//	out << h[i].getID() << endl;*/
	//}

	/*ifstream in("human.txt");
	Human** h = nullptr;
	int size = 0;
	char buff[1024];

	while (in.getline(buff, 1024))
	{
		int a, id;
		in >> a >> id;
		in.get();
		Human *h1 = new Human(buff, a, id);
		addElem(h, size, h1);
	}

	h[0]->print();
	h[1]->print();*/

	/*char buff[1024];
	ifstream in("text2.txt");
	if (in.is_open())
	{
		in.getline(buff, 1024);
	}

	cout << buff << endl;*/


	/*ofstream out("text3.txt", ios::app);
	out << "Hello C++" << endl;*/

	/*Point p;
	p.print();
	p.get();

	cout << PI << endl;
	cout << SQR(5+1) << endl;

	ЦИКЛ(10)
		cout << "mama" << endl;*/

	


//#ifdef TEST
//	int a[SIZE];
//#else
//	int* a = nullptr;
//#endif // TEST

}
