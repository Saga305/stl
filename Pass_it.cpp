//Pass inner container iterator of class to the user application.
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template <typename T,typename Container = vector<T> >
class PassIt
{
public:
	void push(T val);
	typename Container::iterator begin()
    {
        return Obj.begin();
    }
    
   typename Container::iterator end()
    {
        return Obj.end();
    }
private:
	Container Obj;
};

template<typename T,typename Container>
void PassIt<T,Container>::push(T val)
{
     Obj.push_back(val);
}

int main()
{
    PassIt<double> d;
    
    for(int i =0; i< 10; i++)
    {
            d.push(i);
    }
     
    for( auto it = d.begin() ; it != d.end(); it++)
    {
        cout<<*it<<endl;
        
    }
}
