#include <iostream>
#include <stack>
#include <cstring>
using std::cin;
using std::cout;
using std::endl; 
using std::stack;
using std::string;

int main() {
	stack<int> s;
	string opr;
	while (cin >> opr) {
		if (opr == "push") {
			int value;
			cin >> value;
			s.push(value);
		} else if (opr == "pop") {
			if (s.empty()) {
				cout << "stack is empty!" << endl;
				continue;
			}
			cout << "pop : " << s.top() << endl;
			s.pop();
		} else if (opr == "end") {
			break;
		}
	}
	return 0;
}