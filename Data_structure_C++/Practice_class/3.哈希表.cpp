#include <iostream>
#include <stack>
#include <cstring>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl; 
using std::stack;
using std::string;
using std::unordered_map;

int main() {
	unordered_map<string, double> h;
	string opr;
	while (cin >> opr) {
		if (opr == "insert") {
			string name;
			double height;
			cin >> name >> height;
			h[name] = height;
		} else if (opr == "search") {
			string name;
			cin >> name;
			if (h.find(name) == h.end()) {
				cout << "oh no :" << name << "isn't in hashtable!" << endl;
			} else {
				cout << h[name] << endl;
			}
		} else if (opr == "end") {
			break;
		}
	}
	return 0;
}