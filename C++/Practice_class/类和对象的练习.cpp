#include <iostream>
#include <string>
using namespace std;
class Peolple{
public:
	//Peolple(string name);
	Peolple(const string &name); //构造函数 , 声明函数
	Peolple(const Peolple &a) {         //拷贝构造函数
		Peolple::total_num++;
		this->__name = a.__name + "2";
		cout << "copy constructor" << endl;
	} 
	~Peolple() {
		Peolple::total_num--;
	}
	void say(string word) {
		cout << this->__name << " say : " << word << endl;
	}
	void set_name(string __name) {
		this->__name = __name;
	}
	static int get_total() {
		return Peolple::total_num;
	}
private:
	string __name;
	static int total_num;
};

int Peolple::total_num = 0;

//Peolple::Peolple(string name) {
//	this->__name = name;		
//	cout << "Peolple constructor2" << endl; 
//}

Peolple::Peolple(const string &name) {  //外部定义函数
	this->__name = name;
	cout << "Peolple constructor" << endl; 
	Peolple::total_num++;

}

int main() {
	string name = "xiaoxiao";
	Peolple xiaoxu(name);
	Peolple hug("dd");
	hug.say("xx");
	cout << Peolple::get_total() << endl;
	return 0;
}