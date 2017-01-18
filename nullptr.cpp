#include <iostream>
#include <vector> 
using namespace std;

int my_strlen(const char *str) {
	if(str != nullptr) {
		return strlen(str); 
	}
	return 0; 
}

int main() {
	const char *str = nullptr;
	const char *hello_world = "hello world";
	cout << "my_strlen(str) = " << my_strlen(str) << endl;
	cout << "my_strlen(hello_world) = " << my_strlen(hello_world) << endl;
}
