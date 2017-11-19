// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
	// using std::find with array and pointer:
	int myints[] = { 10, 20, 30, 40  };
	int * p;

	p = std::find (myints, myints+4, 30);
	if (p != myints+4)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";

	// using std::find with vector and iterator:
	std::vector<int> myvector (myints,myints+4);
	std::vector<int>::iterator it;

	it = find (myvector.begin(), myvector.end(), 30);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << *it << '\n';
	else
		std::cout << "Element not found in myvector\n";

	char myc[] = { 'A', 'B', 'C', 'D'  };
	char *n1;
	n1= std::find (myc, myc+4, 'C');
	if (n1 != myc+4)
		std::cout << "Element found in myc: " << *n1 << '\n';
	else
		std::cout << "Element not found in myc\n";

	const char *n2;
	const char *str = "hello dear";
	n2= std::find (str, str+10, 'd');
	if (n2 != str+4)
		std::cout << "Element found in myc: " << *n2 << '\n';
	else
		std::cout << "Element not found in myc\n";

	return 0;

}
