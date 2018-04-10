#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<string> q[3]; 
	int opr;
	string str;
	for (int i = 0; i < 10; i++) {
		cin >> opr >> str;
		q[opr].push(str);
	}
	for (int i = 0; i < 10; i++) {
		if(!q[0].empty()) {
			cout << q[0].front() << " ";
			q[0].pop();
		} else {
			cout << "0 ";
		}
		if(!q[1].empty()) {
			cout << q[1].front() << " ";
			q[1].pop();
		} else {
			cout << "0 ";
		}
		if(!q[2].empty()) {
			cout << q[2].front() << endl;
			q[2].pop();
		} else {
			cout << "0" << endl;
		}
	}
	return 0;
}