/*
Template stack implementation using std::vector.
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
public:
	void push(T val);
	T pop();
	bool isEmpty() const;
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
    cout<<"Stack is empty"<<endl;
    exit(-1);
 
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return stackObj.empty();
}

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
    cout<<s.pop()<<endl;
    cout<<((s.isEmpty() == true) ?"true":"false")<<endl;
}
