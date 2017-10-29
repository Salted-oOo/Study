/*
* @Author: alivedreams
* @Date:   2017-10-22 08:50:56
* @Last Modified by:   alivedreams
* @Last Modified time: 2017-10-22 10:17:26
*/
#include <iostream>

using namespace std;

struct B
struct C

struct A {
	struct IVisitor {
		virtual void Accept(B *) = 0;
		virtual void Accept(C *) = 0;
	};
	virtual void Accept(IVisitor *visitor) = 0;
};

struct B : A {
	virtual void Accept(IVisitor *visitor) override {
		visitor->Accept(this);  //this---B*
	}
};

struct C : A {
	virtual void Accept(IVisitor *visitor) override {
		visitor->
		Accept(this);  //this---C*
 	}
};

struct OutputName : A::IVisitor {
	virtual void Accept(B *) {
		cout << "This is class B" << endl;
	} 
	virtual void Accept(C *) {
		cout << "This is class C" << endl;
	}
};

int main() {
	B b;
	A *pa = &b;
	OutputName out;
	pa->Accept(&out);
	return 0;
}