/*
Practice code of the function template.
*/
#include <iostream>
using namespace std;

template<typename T>
double getAvg(T* array, int element)
{
	T tsum = T();

	for(int i= 0; i < element; i++)
	{
		tsum += array[i];
	}

	return double(tsum)/element;
}

int main()
{
	int iArray[] = {1,2,3,4,5,6,7,8,9,10};
	double dArray[] = {1.1, 2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};

	cout<<getAvg(iArray,10)<<endl;
	cout<<getAvg(dArray,10)<<endl;

}
