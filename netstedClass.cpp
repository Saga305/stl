/*Nested class using template */

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Test
{
    private:
        T t;
    public:
        Test():t(T())
        {}
        
        Test(T _t):t(_t)
        {}
        
        void print()
        {
            cout<<"Test: "<<t<<endl;
        }
};


template<typename T,typename Class>
class Classic
{
    private:
        T t;
        Class c;
    public:
        Classic():t(T()),c(T())
        {}
        
        Classic(T _t):t(_t),c(t)
        {}
        
        void print()
        {
                cout<<"Classic: "<<t<<endl;
                c.print();
        }
};


int main()
{
    Classic<int,Test<int> > c(10);
    c.print();
    return 0;
}
