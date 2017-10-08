#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack<int> s;
	int n, element;
	int flag = 1, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> element;
		while (count < element) {
			++count;
			s.push(count);
		}
		if (s.empty() || s.top() != element) {
			flag = 0;
		}
		s.pop();
	}
	cout << (flag == 1 ? "YES" : "NO") << endl;
	return 0;
}	