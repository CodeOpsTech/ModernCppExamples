#include <iostream> 
using namespace std; 

template <int num>	
struct Factorial
{
	static const int fact = num * Factorial < num - 1 > :: fact;
};

template <>			// specialization for 0
struct Factorial<0> // - this serves as a terminating condition
{        
	static const int fact = 1;
};

int main()
{
     cout<< "The factorial of 3 is :" << Factorial<3>::fact;
}
