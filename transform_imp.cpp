//implement your own STD::transform using template.
#include <iostream>
#include <vector>

using namespace std;

int increase (int i) { 
    return ++i; 
}

template<typename T1, typename T2, typename T3>
void transform(T1 itb, T1 ite, T2 sitb, T3 func)
{

    while(itb != ite)
        {
             *sitb = func(*itb);  
             ++sitb;
             ++itb;
        }
 }


int main()
{
    vector<int> vi,iv;
    
    for (int i=0; i<5; i++)
    {
        vi.push_back(i);
    }
    
    iv.resize(vi.size());
    
    transform(vi.begin(),vi.end(),iv.begin(),increase);
    
     for (int i=0; i<5; i++)
    {
        cout<<iv[i]<<endl;
    }
    
    return 0;
}
