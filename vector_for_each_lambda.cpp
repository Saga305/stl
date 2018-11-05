#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using namespace std;

typedef struct temp
{
	int _i;
	char _c;
	double _d;

	temp():_i(0),_c(0),_d(0.0)
	{
	}

	temp(int i,char c,double d):_i(i),_c(c),_d(d)
	{
	}

}TEMP;

int main()
{
	vector<TEMP> vec;
	int i = 0, j = 1;
	char c = 'A';
	double d = 0.0;

	do
	{
		vec.emplace_back(TEMP((i+j),(c+j),(d+j)));
		j++;
	}
	while(j< 20);

	for_each(vec.begin(), vec.end(),[](TEMP &x)
			{
			cout<<" _i:"<<x._i<<" _c:"<<x._c<<" _d:"<<(double)x._d<<std::endl;
			});

	std::sort(vec.begin(), vec.end(),[](TEMP x, TEMP y ) 
			{
				if(y._i > x._i)
				{
					return false;
				}
				else
				{
					return true;
				}
			});

	std::cout<<"AFTER SORTING:"<<std::endl;

	for_each(vec.begin(), vec.end(),[](TEMP &x)
			{
			cout<<" _i:"<<x._i<<" _c:"<<x._c<<" _d:"<<(double)x._d<<std::endl;
			});


	return 0;
}
