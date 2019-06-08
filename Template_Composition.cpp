/*
practice code: Template composition.
*/

#include <iostream>
using namespace std;

template<typename T>
class Test
{
private:
	T t;
public:
	Test(T _t):t(_t)
	{}

	T getT()
	{
		return t;
	}

	friend ostream& operator<<(ostream& os, Test<T> &t)
	{
		os<<"\nValue Test: "<<t.t<<endl;
		return os;
	}

	Test(const Test<T>& t)
		{
			this->t = t.t;
		}

};


template<typename T>
class Testing
{
private:
	Test<T> temp;
	T t;
public:
	Testing(T _t):temp(_t),t(_t)
	{}

	T getT()
	{
		return t;
	}

	friend ostream& operator<<(ostream& os, Testing<T> &t)
	{
		os<<"Value Testings: "<<t.t<<" "<<t.temp<<endl;
		return os;
	}

	Testing(const Testing &t):temp(t.temp)
	{
		this->t = t.t;
	}
};


int main()
{
	Testing<string> t("The Great Saga");
	Testing<string> t2(t);
	cout<<t2;
	return 0;
}
