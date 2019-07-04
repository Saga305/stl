#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

using namespace std;

template <typename T,typename Container = vector<T> >
class Stack
{
public:
	void push(T val);
	T pop();
	bool isEmpty() const;
    T top() const;
private:
	Container stackObj;
};

template<typename T,typename Container>
void Stack<T,Container>::push(T val)
{
    stackObj.push_back(val);
}

template<typename T,typename Container>
T Stack<T,Container>::pop()
{
    if(!stackObj.empty())
    {
        T temp = stackObj.back();
        stackObj.pop_back();
        return temp;
    }
    else
    {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
}

template<typename T,typename Container>
bool Stack<T,Container>::isEmpty() const
{
    return stackObj.empty();
}

template<typename T,typename Container>
T Stack<T,Container>::top () const
{
    if (stackObj.empty()) 
    {
    throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return stackObj.back();
}

int main()
{
    Stack<int,std::deque<int> > s;
    //cout<<s.pop()<<endl;
    s.push(1);
    s.push(2);
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
    
     Stack<double> d;
    d.push(1.5);
    d.push(2.3);
    cout<<d.pop()<<endl;
    cout<<((d.isEmpty() == true) ?"true":"false")<<endl;
    cout<<d.pop()<<endl;
    cout<<((d.isEmpty() == true) ?"true":"false")<<endl;
}
