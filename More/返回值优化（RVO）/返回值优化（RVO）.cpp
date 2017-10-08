#include <iostream>
#include <string>
using namespace std;
 
class People {
public :
    People(string x);
    People(const People &a);
    ~People();
    void out();
    People operator= (People a) {
        a.x = 1;
        cout << this << " operator1= is called" << "  1" << endl;
        return a;
    }
    int operator= (const int x) {
        if (x == 1) {
            this->x = "100";
        } else {
            this->x = "200";
        }
        cout << this << " operator2= is called" << endl;
        return 256;
    }
private :
    string x;
};
 
People func() {
    People temp("test");
    cout << "  3" << endl;
    return temp;
}
 
int main() {
    People a("hug");
    People b = func();
    a = (a = b);

   // a = 1;
    a = func();
    //People __temp1 = a.operator=(People __temp2 = func());
    return 0;
}
 
People::People(string x) : x(x) {
    cout << "constructor by " << this << "  0" << endl;
}
 
People::People(const People &a) {
    this->x = a.x + "0";
    cout << "copy contructor called from " << &a << " to " << this << endl;
}
 
People::~People() {
    cout << this << " destroy" << endl;
}
 
void People::out() {
    cout << this << " name is " << this->x << endl;
    return ;
}