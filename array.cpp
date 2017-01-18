#include <iostream> 
#include <array> 
using namespace std; 

int main() {
	array<string, 2> strs = { string("hello "), string("world") }; 
	cout << strs.at(0) << strs.at(1) << endl; 
}

