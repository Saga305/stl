#include<iostream>
#include<map>
class Base;
using namespace std;

std::map<int,class Base*> _map;

class Base {
	private:
		int a;
	public:
		Base():a(0){}
		void setdata(int a)
		{
			this->a = a;
		}
		int getdata()
		{
			return a;
		}


};

void iterate(Base *ptr)
{
	cout<<ptr->getdata()<<endl;
}

int main()
{
	Base ob[5];
	int i;
	for(i=0; i<5; i++)
	{
		_map.insert(std::make_pair(i,&ob[i]));
		ob[i].setdata(i);
	}

	std::map<int,class Base*>::iterator it;
	for(it = _map.begin(); it != _map.end(); it++)
	{
		iterate(it->second);
	}


	return 0;
}
