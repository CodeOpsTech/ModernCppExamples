#include <iostream> 
using namespace std; 

class Base { 
public: 
	virtual void foo() { cout << "in Base::foo" << endl; }
};

class Derived : public Base { 
public: 
	virtual void foo() override { cout << "in Derived::foo" << endl; } 
};

int main() {
	std::unique_ptr<Base> uptr = std::make_unique<Derived>(); 
	uptr->foo(); 
}

