//static polymorphism
/*
Polymorphism is not for free. We need to pay some cost of price for that. Two of the I know are.
1. Memory cost of virtual table.
2. Run time cost of dynamic binding. 
*/
#include <iostream>
using namespace std;
template <class T>
class A {
	int a,b;

	public:
	A(){ a = 0; b = 0; }
	int calculation ( int a, int b )
	{
		return add(a,b);

	}

	int add (int a, int b)
	{
		return static_cast<T*>(this)->add(a,b);

	}

};

class B:public A<B>
{
	public:
		int add ( int a, int b )
		{
			return a+b;

		}

};

int main() {
	B b;
	cout<< b.calculation (5,5)<<endl;
	return 0;

}
