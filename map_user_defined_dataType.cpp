#include <map>
#include <iostream>

using namespace std;

typedef struct USERDEFIND
{
	int i;
	char c;

	USERDEFIND():i(0),c(0)
	{}

	/***************************************************************************************************
	  Compiler won't allow to compile this if we didn't overload comparision operator. Basically this comparision operator decides the insertion order. To understand do following changes and check.

	  return (this->i < t.i); 
	  with 

	  return (this->i > t.i);
	  and 
	  return (this->i == t.i);
	 ****************************************************************************************************/
	bool operator<(const struct USERDEFIND& t) const
	{ 
		return (this->i < t.i); 
	} 
}udef;

class Test
{
	private:
		map<udef,int> _map;
	public:
		void insertData()
		{
			for (int i = 0; i < 26; i++)
			{
				udef u;
				u.i = 1 + i;
				u.c = 'A' + i;
				_map.insert(make_pair(u,i));
			}
		}

		void printData()
		{
			for( auto& it : _map)
			{
				cout<<"Key : "<<(it).first.i<<" "<<(it).first.c<<" Value :"<<(it).second<<std::endl;
			}
		}

};

int main()
{
	Test t;
	t.insertData();
	t.insertData();
	t.printData();

	return 0;
}
