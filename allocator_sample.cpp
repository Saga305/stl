#include <iostream>

#include <vector>

using namespace std;

template<typename T>

class Allocator

{

private: 

char* ptr;

public:

Allocator()

{

ptr = nullptr;

}

~Allocator()

{

if(ptr)

delete[] ptr;

}

T* allocate(int sz)

{

ptr = new char[sz * sizeof(T)];

return (T*)ptr;

}

void deallocate(T* arr, int sz)

{

for(unsigned int i =0 ; i < (sz * sizeof(T)); i= i+sizeof(T))

{

arr[i].~T();

}

delete[] ptr;

}

void construct(T* ptr, const T& val)

{

new(ptr) T(val);

}

void destroy(T* ptr)

{

ptr->~T();

}

};

class Test

{

public:

Test(int i = 0)

{

cout<<"Default Constructor Called: "<<i<<endl;

}

Test(const Test& t)

{

cout<<"Copy constructor called"<<endl;

}

~Test()

{

cout<<"Destructor Called"<<endl;

}

private:

int i;

};

int main()

{

Allocator<Test> myAllocator; 

// allocate space for three strings 

Test* str = myAllocator.allocate(3); 

// construct these 3 strings 

myAllocator.construct(str, 1); 

myAllocator.construct(str + 1,2); 

myAllocator.construct(str + 2, 3); 

// destroy these 3 strings 

myAllocator.destroy(str); 

myAllocator.destroy(str + 1); 

myAllocator.destroy(str + 2); 

std::cout << "CHecking why extra destructor called"<<std::endl;

// deallocate space for 3 strings 

myAllocator.deallocate(str, 3); 

return 0;

} 

