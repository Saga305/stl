#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
	int n1 = 13;

	std::vector<int> vim;
	std::vector<std::vector<int>> vec;
	vec.push_back(vim);
	 for(int i = 10; i < 15; i++)
	 {

		  vec[0].push_back(i);
			       
	 }
	std::vector<int>::iterator result1;
	result1 = std::find(std::begin(vec[0]), std::end(vec[0]), n1);

	if (result1 != std::end(vec[0])) {
		std::cout << "vec[0] contains: " << n1 << '\n';

	} else {
		std::cout << "vec[0] does not contain: " << n1 << '\n';

	}



}
