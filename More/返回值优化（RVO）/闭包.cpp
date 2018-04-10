#include <iostream>
using namespace std;
auto Range = [](char b, char e) {   //[]
	return[=](char x){
		return x >= b && x <= e;
	};
};

auto is_upper = Range('A', 'Z');
auto is_lower = Range('a', 'z');
auto is_digit = Range('0', '9');

int main() {
	char c;
	while(scanf("%c", &c) != EOF) {
		printf("%d : %d%d%d\n", c, is_upper, is_lower, is_digit);
	}
	return 0;
}