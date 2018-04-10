#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
using namespace std;


int precede(int operators1, int operators2) {
    int count1, count2;
    if (operators1 == '+' || operators1 == '-') {
        count1 = 1;
    } else {
        count1 = 2;
    }
    if (operators2 == '+' || operators2 == '-') {
        count2 = 1;
    } else {
        count2 = 2;
    }
    return count1 > count2; 
}
int operate(int operators, int a, int b) {
    if (operators == '+') return a + b;
    else if (operators == '-') return b - a;
    else if (operators == '*') return a * b;
    else if (operators == '/') return b / a;
    else return 0;
}
void calc(stack<int> &numbers, stack<int> &operators) {
    int a, b;
    a = numbers.top();
    numbers.pop();
    b = numbers.top();
    numbers.pop();
    numbers.push(operate(operators.top(), a, b));
    operators.pop();
}


int main() {
	stack<int> numbers, operators;
	char str[25], buffer[30];
	int n;
	cin >> str;
	//cout << str << endl;
	n = strlen(str);
	strcpy(buffer, str);
	//cout << buffer << "  " << n << endl;
	int i  = 0;
	while (i < n) {
		if (isdigit(buffer[i])) {
			numbers.push(buffer[i] - '0');
			i++;
		} else {
			if (operators.empty() || precede(buffer[i], operators.top())){
				operators.push(buffer[i]);
				i++;
			} else {
				calc(numbers, operators);
			}
		}
	}
	while (!operators.empty()) {
		calc(numbers, operators);
	}
	cout << numbers.top() << endl;
	return 0;
}

