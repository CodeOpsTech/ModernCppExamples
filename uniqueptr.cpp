#include <iostream> 
#include <memory> 
using namespace std; 

class Base { 
public: 
	Base() { cout << "in Base()" << endl; } 
	virtual void foo() { cout << "in Base::foo" << endl; }
	virtual ~Base() { cout << "in ~Base()" << endl; } 
};

class Derived : public Base { 
public: 
	Derived() { cout << "in Derived()" << endl; } 
	virtual void foo() override { cout << "in Derived::foo" << endl; } 
	virtual ~Derived() { cout << "in ~Derived()" << endl; } 
};

int main() {
	std::unique_ptr<Base> uptr1 = std::make_unique<Derived>(); 
	std::unique_ptr<Base> uptr2 = std::move(uptr1); 
	uptr2->foo(); 
}

