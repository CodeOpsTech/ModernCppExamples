#include <iostream> 
using namespace std;

int main() {
	int x = 10;
	decltype(x) y = 20;
	auto z = y;
	cout<< "x = " << x << " y = " << y << " z = " << z << endl;
}

