#include <iostream>
using namespace std;

int main() {
	using str_literal = const char *; 
	str_literal hello_world = "hello world";
	cout << hello_world << endl; 

	using fp = int (*)(const char *, const char *); 
	fp strcomparer = strcmp; 
	cout << strcomparer("hello", "hello") << endl; 
}
