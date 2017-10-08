#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int year;
    cin>>year;
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}