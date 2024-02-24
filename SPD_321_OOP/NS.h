#pragma once
#include<iostream>


using namespace std;

namespace Foo
{
	void foo()
	{
		cout << "Foo::Foo" << endl;
	}

	namespace Doo
	{
		void foo()
		{
			cout << "Doo::Foo" << endl;
		}
	}
}

namespace Boo
{
	void foo()
	{
		cout << "Boo::Foo" << endl;
	}
}