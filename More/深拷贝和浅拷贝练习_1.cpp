#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//template<typename T>

class Element {
private:
	char *str;
	int count;
public:
	Element(int count = 10) : count(count) {
		malloc(sizeof(char) * this->count);
		cout << "This is Element 1 : " << endl;
	}
	Element(const Element& element) : count(element.count) {
		//memcpy(this->str, element.str, sizeof(char) * this->count);
		cout << "This is Element 2 : " << endl;
 	}
	~Element() {
		//for (int i = 0; i < this->count; i++) {}
		//free(str);
		delete[] this->str;
		cout << "This is Element 3 : " << endl;
	}



/*   Element() :number(0) {
        cout << "ctor" << endl;
    }
    Element(int num):number(num) {
        cout << "ctor" << endl;
    }
    Element(const Element& e):number(e.number) {
        cout << "copy ctor" << endl;
    }
    Element(Element&& e):number(e.number) {
        cout << "right value ctor" << endl;
    }
    ~Element() {
        cout << "dtor" << endl;
    }
  */
};



class Vector {
private:
	Element* items;
	int size;
	int count;
public:

//	Vector() : count{ 0 }, items{ nullptr } {}
    Vector(int n = 10) : size(n), count(0) {
        this->items = (Element *)malloc(sizeof(Element) * this->size);
        cout << "This is Vector 1 : " << endl;
    }

	Vector(const Vector& vector) : size(vector.size), count{vector.count} {
		//items = static_cast<Vector*>(malloc(sizeof(Vector) * count));
		memcpy(this->items, vector.items, this->size);
		cout << "This is Vector 2 : " << endl;
	}

//	Vector(const Vector&& vector) : count{vector.count}, items{vector.items} {
//		vector.count = 0;
//		vector.items = nullptr;
//	}

	~Vector() {
		for (int i = 0; i < this->count; i++) {
			this->items[i].~Element();
		}
		free(this->items);
		this->items = nullptr;
		this->count = 0;
		this->size = 0;
		cout << "This is Vector 3 : " << endl;
	}


    void Add(const Element& item) {
        Element *buffer = (Element *)malloc(sizeof(Element) * (this->count + 1));
        for (int i = 0; i < this->count; i++) {
            new(buffer + i)Element(std::move(this->items[i]));
        }
        new(buffer + this->count)Element(item);
        int total_count = this->count + 1;
        //this->Clear();
        this->count = total_count;
        this->items = buffer;
        return ;
    }


 /*   void Add(const Element& element) {
        if (this->count >= this->size) {
            return ;
        }

        new(this->items + this->count)Element(element);
        (this->count)++;
        cout << "This is Add : " << endl;
        return ;
	}
*/

};

Element func(){
	Element test;
	return test;
}


int main() {  
	Vector test1;
	Element ele1;
	test1.Add(ele1);
	test1.Add(func());
	test1.Add(func());
	test1.Add(func());
	//Vector test2(test1);
	return 0;
}
