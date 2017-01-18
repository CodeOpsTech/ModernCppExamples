#include <iostream>
using namespace std;

int main() {
	auto equals = [](auto i, auto j) { return (i == j); };
	cout << "equals(10, 20) is " << equals(10, 10) << endl;
}
