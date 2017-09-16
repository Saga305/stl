#include <iostream>
using namespace std;


template<class T>
struct ST
{
	T v;
};


int main()
{
	struct ST<int> i;
	i.v = 20;
	cout<<i.v<<endl;

	struct ST<float> f;
	f.v = 30.4f;
	cout<<f.v<<endl;

	struct ST<std::string> s;
	s.v = "The Great Saga";
	cout<<s.v<<endl;

	return 0;
}
