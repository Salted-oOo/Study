/*
* @Author: alivedreams
* @Date:   2017-10-20 16:27:52
* @Last Modified by:   alivedreams
* @Last Modified time: 2017-10-21 08:37:27
*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class test
{
public:
	test(int len = 10) : length(len){
		//str = (char *)malloc(sizeof(char) * this->length);
		this->str = new char[this->length];
		cout << "This is test 1" << endl;
	}
	test (const test& Last) : length(Last.length) {
		str = (char *)malloc(sizeof(char) * this->length);
		memcpy(this->str, Last.str, this->length);
		cout << "This is test 2" << endl;
	}
	~test() {
		//free(this->str);
		delete[] this->str;
		cout << "This is test 3" << endl;
	}
private:
	char *str;
	int length;
};

class wrong
{
public:
	wrong(int len = 10) : length(len){
		this->str = (test *)malloc(sizeof(test) * this->length);
		cout << "This is wrong 1" << endl;
	}
	wrong(const wrong& Last) : length(Last.length) {
		str = (test *)malloc(sizeof(test) * this->length);
		memcpy(this->str, Last.str, this->length);
		cout << "This is wrong 2" << endl;
	}
	~wrong() {
		//for (int i = 0; i < this->length; i++) {
			//free(this->str[i])
		//}
		//free(this->str);
		str[0].~test();
		free(this->str);
		cout << "This is wrong 3" << endl;
	}

	void Add(const test& Last) {
		new(this-> str )test(Last);
		//this->length++;
		return ;
	}
private:
	test *str;
	int length;
};

test func() {
	test a;
	return a;
}

int main() {
	wrong w1;
	//b.~wrong();
	//wrong w2;
	//test t1;
	//w1.Add(t1);
	w1.Add(func());
	wrong w3(w1);
	return 0;
}