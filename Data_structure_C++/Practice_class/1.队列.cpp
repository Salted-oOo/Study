#include <iostream>
#include <queue>
#include <cstring>
using std::cin;
using std::cout;
using std::endl; 
using std::queue;
using std::string;

int main() {
	queue<int> q;
	string opr;
	while (cin >> opr) {
		if (opr == "push") {
			int value;
			cin >> value;
			q.push(value);
		} else if (opr == "opr") {
			cout << "pop : " << q.front() << endl;
			q.pop();
		} else if (opr == "end") {
			break;
		}
	}
	return 0;
}