#include <iostream>
using namespace std;

#define MAX_N 200

int prime[MAX_N] = {0};

int rand() {
	static int plus = 1;
	do {
		plus *= 10007;
		plus %= 10079;
	} while (plus > 10000);
	return plus;
}

int main() {
	int arr[10001] = {0};
	for (int i = 0; i < 10000; i++) {
		int x = rand();
		cout << rand() << endl;
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum = sum + i;
	}


/*	int x = 3;
	int p = 5;
	int plus = 1;
	for (int i = 0; i < p; i++) {
		cout << 3 << "^" << i << " % "<< 
			    p << "=" << plus << endl;
		plus *= x;
		plus %= p;
	}
*/

	return 0;
}