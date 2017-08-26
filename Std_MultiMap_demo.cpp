#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

struct Student
{
	int roll_no;;
	float percentage;
};

std::multimap<std::string,struct Student> _map;

void fillMap(string name, int no, float per)
{
	struct Student st;
	st.roll_no = no;
	st.percentage = per;
	_map.insert(std::make_pair(name,st));
}

int main()
{
	fillMap("Raja",4,69.7f);
	fillMap("karma",2,81.7f);
	fillMap("edric",3,69.7f);
	fillMap("Raja",1,80.7f);   

	std::multimap<std::string,Student>::iterator it;
	cout<<"Name"<<"\t"<<"rollNo"<<"\t"<<"percentage"<<endl;
	for(it = _map.begin(); it != _map.end(); it++)
	{
		cout<<it->first<<"\t"<<it->second.roll_no<<"\t"<<it->second.percentage<<endl;
	}
	return 0;
}

