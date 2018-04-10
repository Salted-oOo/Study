#include <iostream>
using namespace std;

//#define Print(a) (cout << a << endl) 
//#define Point(T)  \
	struct Point##_##T {  \
		T a, b;  \
	};

template<typename T>
void Print(const T &a) {
	cout << a << endl;
}


template<typename T>
struct Point {
	T a, b;
};
//Point(int)
//Point(double)

int main() {
	//Point_int p ={1, 2};
	//Point_double q = {2.5, 5.2};
	Point<int> p1 = {1, 2};
	Point<double> q1 = {3.2, 6.5};
	Print(p1.a);
	Print(p1.b);
	Print(q1.a);
	Print(q1.b);
	int a = 8;
	Print(a);
	double b = 2.55;
	Print(b);
	char c = 'A';
	Print(c);
	return 0;
}