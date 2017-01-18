#include <iostream> 
#include <array> 
using namespace std; 

int main() {
	const char *cstrs[] = { "hello ", "world" };
	constexpr int arr_len = sizeof(cstrs) / sizeof(char*); 
	array<string, arr_len> strs = { cstrs[0], cstrs[1] }; 
	cout << strs.at(0) << strs.at(1) << endl; 
}

