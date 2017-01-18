#include <iostream> 
#include <string>
#include <map> 
using namespace std;

template <class Type> 
void print_type_info(const Type & t)
{
    std::cout << typeid(t).name() << std::endl;
}

int main()
{
    map<int, int> m; 
    print_type_info(m); 
    string s; 
    print_type_info(s); 
    int i = 10;
    print_type_info(i); 
}

