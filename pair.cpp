#include <iostream>
#include <typeinfo>

template <typename T, typename U>
class pair
{
        public:
            
            T first;
            U second;
            
            pair(T t= T(), U u=U()):first(t),second(u)
            {}           
            
            bool operator==(pair rhs)
            {
                    if(first == rhs.first && second == rhs.second)
                    {
                        return true;
                    }
                    return false;
            }
            
            bool operator!=(pair rhs)
            {
                    if(*this == rhs)
                    {
                        return false;
                    }
                    return true;
            }
            
            bool operator<(pair rhs)
            {
                    if((first < rhs.first) && (second <rhs.second))
                    {
                        return true;
                    }
                    return false;
            }
            
            bool operator>(pair rhs)
            {
                    if(*this < rhs)
                    {
                        return false;
                    }
                    return true;
            }
            
            bool operator<=(pair rhs)
            {
                    if((*this == rhs) || (*this < rhs))
                    {
                        return true;
                    }
                    return false;
            }
            
            bool operator>=(pair rhs)
            {
                    if((*this == rhs) || (*this > rhs))
                    {
                        return true;
                    }
                    return false;
            }
};
    
template<typename V, typename W>
pair<V, W> make_pair(V t, W u)
{
    return pair<V,W>(t,u);
}

template<typename T,typename U>
void swap( pair<T,U>& x, pair<T,U>& y )
{
        pair<T,U> temp;
        temp = x;
        x = y;
        y = temp;
}

template<std::size_t _Int>
struct __pair_get;

template<>
struct __pair_get<0>
    {
      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp1&
        __get(pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.first; }
    };
    
template<>
struct __pair_get<1>
    {
      template<typename _Tp1, typename _Tp2>
        static constexpr _Tp2&
        __get(pair<_Tp1, _Tp2>& __pair) noexcept
        { return __pair.second; }
    };    
    
template<std::size_t _Int, class _Tp1, class _Tp2>
constexpr auto get(pair<_Tp1, _Tp2>& __in) -> decltype ((_Int == 0) ? __in.first: __in.second)
    { return __pair_get<_Int>::__get(__in); }
    
template<class T, class _Tp1, class _Tp2>
constexpr auto get(pair<_Tp1, _Tp2>& __in)
    { 
            return typeid(T) == typeid(__in.first) ? __in.first : __in.second;          
    }
    
int main()
{

    pair <int, char> PAIR1 = make_pair<int,char>(300,'B');
    pair <int, char> PAIR2 = make_pair<int,char>(200,'A');
    
    std::cout << PAIR1.first << " " ; 
    std::cout << PAIR1.second << std::endl ; 
    
    std::cout << PAIR2.first << " " ; 
    std::cout << PAIR2.second << std::endl ; 
    
    swap<int,char>(PAIR1,PAIR2);
    
    std::cout << PAIR1.first << " " ; 
    std::cout << PAIR1.second << std::endl ; 
    
    std::cout << PAIR2.first << " " ; 
    std::cout << PAIR2.second << std::endl ; 
    
    auto p = make_pair(100, 3.14);
    std::cout << '(' << get<0>(p) << ", " << get<1>(p) << ")\n";
    std::cout << '(' << get<int>(p) << ", " << get<double>(p) << ")\n";
      
    return 0;
}
