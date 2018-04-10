#include <iostream>
#include <string>
using namespace std;

class Object{
public:
	virtual void run() = 0;
};

class Animal : public Object{
public:
	Animal(const string name) : __name(name){}
	//Animal(){
		//cout << "default constructor" << endl;
	//}
	Animal(const Animal &a) : __name(a.__name){
		cout << "copy constructor" << endl;
	} //this->__name = a.name;
	void out() {
		cout << "This Animal name is " << this->__name << endl;;
	}
	void set(string t) {
		this->__name = t;
	}
	virtual void run() = 0;  
	//virtual void run(){
	//	cout << "I don't know how can run" << endl;
	//}
	~Animal(){}
private:
	string __name;
};

class tail {
public:
	tail() {
		cout << "tail constructor" << endl;
	}
	~tail() {
		cout << "tail destruct" << endl;
	}
};

class Cat : public Animal {
public:
	Cat() : Animal("cat"){
		//cout << "Cat constructor" << endl;
	}
	~Cat() {
		cout << "Cat destruct" << endl;
	}
	Cat(const Cat &a) : Animal(a) {}
	Cat &operator=(const Cat &a) {

		this->Animal::operator=(a);
		return *this;
	}
	void run() override {
		cout << "I can run with four legs" << endl;
	}
};



int main() {
	Cat a;
	Animal &b = a;
	Animal *c = &a;
	Object *d = &a;
	Animal e;
	e.run();
	a.run();
	b.run();
	c->run();
	d->run();
	return 0;
}