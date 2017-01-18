#include <iostream>
#include <vector> 
using namespace std;

class Test {
public: 
	Test() { cout << "constructing Test" << endl; } 
}; 

int main() {
	int i = { 10 };
	cout << "i = " << i << endl; 
	auto j{ 20 }; 
	cout << "j = " << j << endl; 
	vector<int> vec { 30, 40, 50}; 
	cout << "vec = "; 
	for(auto elem : vec)
		cout << elem << " "; 
	cout << endl; 
	Test t{}; 
}
