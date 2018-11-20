/*******************************************************************************************************************

  SAGA@SAGA-Inspiron-5520:~/Practice/design_patterns/design_pattern_cpp$ c++ smart_pointers.cpp -std=c++11 -o str
  SAGA@SAGA-Inspiron-5520:~/Practice/design_patterns/design_pattern_cpp$ ./str 
  Constructor called
  Wadiaaa Hain!!!
  Pal Pal Dil Ke Pass Tum Rehti Ho!!!...
  Constructor called
  Wadiaaa Hain!!!
  Pal Pal Dil Ke Pass Tum Rehti Ho!!!...
  Destructor called
  Destructor called
 *********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;
class String
{
	private:
		char * str;
	public:
		String()
		{
			cout<<" Constructor called"<<std::endl;
			str = new char[100];
			strcpy(str,"Wadiaaa Hain!!!");
		}

		~String()
		{
			cout<<" Destructor called"<<std::endl;
			delete str;
		}

		std::string getString()
		{
			return str;
		}

		void setStr()
		{
			strcpy(str,"Pal Pal Dil Ke Pass Tum Rehti Ho!!!...");
			return;
		}
};

void setString(String *s)
{
	s->setStr();
	return;
}

int main()
{
	//	SHARED POINTER
	std::vector< shared_ptr<String> > vecs;
	shared_ptr<String> sp(new String());
	std::cout<<(sp->getString())<<std::endl;
	vecs.push_back(sp);
	setString(sp.get());
	std::cout<<(vecs[0]->getString())<<std::endl;

	//     UNIQUE POINTER
	std::vector< unique_ptr<String> > vec;
	auto up = std::unique_ptr<String>(new String());
	std::cout<<(up->getString())<<std::endl;
	setString(up.get());
	vec.push_back(std::move(up));
	std::cout<<(vec[0]->getString())<<std::endl;
	return 0;
}
