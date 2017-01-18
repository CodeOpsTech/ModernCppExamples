#include <iostream> 
#include <memory> 
using namespace std; 

class Y; 

class X { 
public: 
	shared_ptr<Y> yptr; 
	X() { cout << "in X()" << endl; } 
	~X() { cout << "in ~X()" << endl; } 
};

class Y { 
public: 
	weak_ptr<X> xptr;  // for correctness, use weak_ptr instead 
	Y() { cout << "in Y()" << endl; } 
	~Y() { cout << "in ~Y()" << endl; } 
};

void create_cycle() {
	auto xptr = make_shared<X>(); 
	auto yptr = make_shared<Y>(); 
	xptr->yptr = yptr;
	yptr->xptr = xptr; 
	cout << "X's use_count " << xptr.use_count() << endl; 
	cout << "Y's use_count " << yptr.use_count() << endl; 
} 

int main() {
	cout << "Before calling create_cycle" << endl; 
	create_cycle(); 
	cout << "After calling create_cycle" << endl; 
}

