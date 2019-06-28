#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define sz(a) int((a).size())
#define insert(container,ele) container.insert(ele)

#define all(c) c.begin(), c.end()

#define tr(container,it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
      
#define present(container, element) (container.find(element) != container.end())

#define cpresent(container, element) (find(all(container),element) != container.end())

#define out(ele) cout<<ele<<endl

#define out2(ele1,ele2) cout<<ele1<<ele2<<endl

typedef set< int > Si;

int main()
{
    Si si;
    
    for(int i=10; i >0; i--)
    {
        insert(si,i);
    }
    
     tr(si,it)
    {
        out(*it);
    }
    
    if(present(si,10))
    {
        //cout<<"10 is present into the set."<<endl;
        out("10 is present into the set.");
    }
    
    if(cpresent(si,11))
    {
        out("11 is present into the set.");
    }
    
    out2("Size: ",sz(si));
    
    return 0;
}
