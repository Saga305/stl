//Non-type class template example using stack.

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T, int MAXSIZE>
class Stack
{
    private:
        T elems[MAXSIZE];
        int numOfElements;
        
    public:
        Stack():numOfElements(-1)
        {}
        
        void push(const T& ele)
        {
                if(numOfElements < MAXSIZE)
                {
                    numOfElements++;
                    elems[numOfElements] = ele;
                    
                }
                else
                {
                    throw std::out_of_range("Stack:: push overflowed");
                }        
        }
        
        const T& pop()
          {
                if(numOfElements < 0)
                {
                        throw std::out_of_range("Stack is empty");
                }
                else
                {
                        numOfElements--;
                        return elems[numOfElements + 1];
                }
          }
          
          bool empty() const 
          {
                return numOfElements == -1;
          }
            
          bool full() const 
          {
                return numOfElements == MAXSIZE;
          }
         
          const T& top()
          {
                if(numOfElements == -1)
                {
                    throw std::out_of_range("Stack is empty");
                }
                else
                {
                    return elems[numOfElements];
                }
         }
};

int main()
{
        Stack<int, 20> s;
        
        for(int i = 0; i < 10;  i++)
        {
            s.push(i);
        }
        
        cout<<"Top: "<<s.top()<<endl;
         for(int i = 0; i < 12;  i++)
        {
           cout<<s.pop()<<endl;
        }
       return 0;
}
