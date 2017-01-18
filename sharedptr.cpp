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
	shared_ptr<Base> ptr1 = make_shared<Derived>(); 
	shared_ptr<Base> ptr2 = ptr1; 
	cout<< "use count is: " << ptr1.use_count() << endl; 
	ptr2->foo(); 
}

