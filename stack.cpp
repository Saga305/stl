/*
Template stack implementation using std::vector.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
public:
	void push(T val);
	T pop();
	bool isEmpty() const;
    T top() const;
private:
	vector<T> stackObj;
};

template<typename T>
void Stack<T>::push(T val)
{
    stackObj.push_back(val);
}

template<typename T>
T Stack<T>::pop()
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

template<typename T>
bool Stack<T>::isEmpty() const
{
    return stackObj.empty();
}

template<typename T>
T Stack<T>::top () const
{
    if (stackObj.empty()) 
    {
    throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return stackObj.back();
}

int main()
{
    Stack<int> s;
    //cout<<s.pop()<<endl;
    s.push(1);
    s.push(2);
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
}
