//placement new technic used to avoid multiple switching between user space to kernel space.

#include<iostream>
#include<stdlib.h>

using namespace std;
int const n = 2;

class Base{
	public:
		int var;
		Base() { cout<<"Constructor"<<endl;}
		Base(int i) {
			cout<<"Constructor "<<"var = "<<i<<endl;
			var = i;
		}
		~Base() { cout<<"Destructor"<<endl;}
		void print() {
			cout<<"var = "<<this->var<<endl;
		}

};
int main()
{
	int size = sizeof(Base) * n;
	cout<<"Allocated memory size = "<<size<<endl;

	//Allocating memory using malloc
	char *mem =(char *) malloc (size);

	//Creating objects on the allocated memory using the placement new and explicitly calling consturctor
	Base *ob1 = new(&mem[0]) Base(10);
	Base *ob2 = new(&mem[4]) Base(20);

	//operation on the created objects
	ob1->print();
	ob2->print();

	//Explicitely calling destructor
	ob1->~Base();
	ob2->~Base();

	//free memory allocated using malloc
	free(mem);
	return 0;
}
