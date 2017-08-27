//Demo of Over Allocation method of allocating and deallocating memory.

#include<iostream>
#include<cstdlib>
#define WORDSIZE 4
#define NO 2

using namespace std;

class Student
{
	int age;

	public:
	Student()
	{
		age=0;
	}
	Student(int age)
	{
		cout<<"Constructor "<< " age = "<<age<<endl;
		this->age=age;
	}
	~Student()
	{
		cout<<"Destructor"<<endl;
	}
	void show()
	{
		cout<<"age =\t"<<age<<endl; 
	}
	static void * Allocate (size_t size)
	{
		cout<<"Allocated Size = "<<size<<endl;
		char *ptr = (char *) malloc (WORDSIZE + NO * sizeof(Student));
		if(ptr)
		{
			Student *p = (Student *) (ptr +WORDSIZE);
			*(size_t*)ptr = size;
			for(int i=0; i<NO; i++)
			{
				new (p + i) Student(i+10);
			}
			return p;	
		}
		else
		{
			cout<<"Unable to allocate"<<endl;
			exit(-1);
		}
	}
	static void Dealloc(void * ptr)
	{
		size_t n = *(size_t*) ((char*)ptr - WORDSIZE);
		cout<<"Size which needs to free = "<<n<<endl;
		int *p = (int *) ptr;
		for(int i = NO-1; i>=0; i--)
		{
			((Student*)(p + i))->~Student();
		}
		free((char *) ptr - WORDSIZE);
	}
};

int main()
{
	char *mem= (char *)Student::Allocate(NO * sizeof(Student));
	Student *ob1 = (Student *) mem;
	Student *ob2 = (Student *) (mem +sizeof(Student));

	ob1->show();
	ob2->show();

	Student::Dealloc(mem);
	return 0;
}
