#include <iostream>
#include <vector>

using namespace std;

class Test
{
    public:
        Test()
        {
            cout<<"Default Constructor Called"<<endl;
        }
        
        Test(const Test& t)
        {
            cout<<"Copy constructor called"<<endl;
        }
        
        ~Test()
        {
            cout<<"Destructor Called"<<endl;
        }
};
            
int main()
{
    vector<Test> t;
    Test t1;
    cout<<"Before push"<<endl;
    t.push_back(t1);
    t.push_back(t1);
    t.push_back(t1);
    cout<<t.data()<<endl;
    cout<<"Size: "<<t.size()<<" capacity:"<<t.capacity()<<endl;
    cout<<"===============BEFORE SHRINK TO FIT======================"<<endl;
    t.shrink_to_fit();
    cout<<t.data()<<endl;
    cout<<"Size: "<<t.size()<<" capacity:"<<t.capacity()<<endl;
    return 0;
}

/*   RESULTS

Default Constructor Called
Before push
Copy constructor called
Copy constructor called
Copy constructor called
Destructor Called
Copy constructor called
Copy constructor called
Copy constructor called
Destructor Called
Destructor Called
0x7715a0
Size: 3 capacity:4
===============BEFORE SHRINK TO FIT======================
Copy constructor called
Copy constructor called
Copy constructor called
Destructor Called
Destructor Called
Destructor Called
0x7715d8
Size: 3 capacity:3
Destructor Called
Destructor Called
Destructor Called
Destructor Called

*/
