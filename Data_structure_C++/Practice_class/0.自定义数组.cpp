#include <iostream>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <ext/hash_map>
using std::cin;
using std::cout;
using std::endl; 
using std::stack;
using std::string;
using std::unordered_map;
using __gnu_cxx::hash_map;

template<typename T> 
struct hash_string {
	hash_string(int size) {
		this->data = new T[size];
		this->size = size;
	}
	T operator[](const_int &ind) {
		T temp;
		if (ind < 0 || ind >= this->size) {
			cout << "segment fault !" << endl;
			return this->nil;
		} else {
			return this->data[ind];
		}
	}
	//void reverse(int n) {

	//}
	T *data;
	int size;
	T nil;
};

struct hash_string {
	size_t operator()(const string &a) const {
		int __h = 0;
		for (int i = 0; i < a.length(); i++) {
			__h = (__h << 5) ^ a[i] ^ (__h >> 3);
		}
		return (size_t)__h;
	}
};

template<typename T>
void swap(T &a, T &b) {
	T c;
	c = a;
	a = b;
	b = c; 
}

int main() {
	array<int> a(100);
	array<double> b(100);
	array<string> c(100);
	a[1] = 2, a[2] = 3; a[3] = 5;
	cour << a[1] << " " << a[2] << endl;
	swap(a[1], a[2]);
	cour << a[1] << " " << a[2] << endl;
	a[65] = 123;
	b[65] = 7.066;
	c[65] = "Hello World !";
	cout << a[65] << " " << b[65] << " " << c[65] << endl;
	a[105] = 6578;
	b[103] = 555;
	return 0;
}