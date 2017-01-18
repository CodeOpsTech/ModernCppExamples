#include <iostream> 
using namespace std; 

class Base { 
public: 
	virtual void foo() { cout << "in Base::foo" << endl; }
	void bar() = delete; 
};

class Derived : public Base { 
public: 
	virtual void foo() { cout << "in Derived::foo" << endl; } 
};

int main() {
	std::unique_ptr<Base> uptr = std::make_unique<Derived>(); 
	uptr->foo(); 
	// uptr->bar();  // this will issue an error - attempt to use deleted function 
}

