#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
	Animal(string name) : __name(name) {
		cout << "Animal construtor" << endl;
	}
//	Animal() {}
	void set_name(string name) {
		this->__name = name;
	}
	void tell_me_your_name() {
		cout << "My name is : " << this->__name << endl;
	}
protected: 
	string __name;
};

class Cat : public Animal{
public:
	Cat() : Animal("temp_name") {
		this->tail = 1;
		cout << "Cat construtor" << endl;
	}
	Cat(tring name) : Animal(name) {
		cout << "Cat construtor" << endl;
	};
	void tell_me_your_name() {
		cout << "Cat name is : " << this->__name << endl;
	}
private:
	int tail;
};

class Tail {
public:
	Tail(int length) : __length(length) {
		cout << "Tail construtor" << endl;
	}
private:
	int __length;
}

class HasTailCat : public Cat {
public:
	HasTailCat(string name) : tail(6) {
		cout << "HasTailCat construtor" << endl;
		this->__name = name;
	}
private:
	Tail tail;
}

int main() {
	Cat a;
//	a.set_name("OK");
    HasTailCat a("garfiled");
	a.tell_me_your_name();
	return 0;
}