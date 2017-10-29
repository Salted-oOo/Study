#include <iostream>
#include <cstring>
using namespace std;

class Accet {
private :
    int *data;
    int length;
public :
    Accet(int len = 10) : length(len) {
        this->data = new int[this->length];//malloc(sizeof(int) * len);
    }
    Accet(const Accet& aa) : length(aa.length) {
        //memcpy(this->data, aa.data, sizeof(int) * this->length);
    }
    ~Accet() {
        //free(this->data);
        delete[] this->data;
    }
};

class Testt {
private :
    Accet *arr;
    int length;
    int size;
public :
    Testt(int len = 10) : size(len), length(0) {
        this->arr = (Accet *)malloc(sizeof(Accet) * this->size);
    }
    Testt(const Testt& tt) : size(tt.size), length(tt.length) {
        memcpy(this->arr, tt.arr, this->size);
       /* this->arr = (Accet *)malloc(sizeof(Accet) * this->size);
        for (int i = 0; i < this->length; ++i) {
            new(this->arr + i)Accet(*(tt.arr + i));
        }*/
    }
    ~Testt() {
        for (int i = 0; i < this->length; ++i) {
            this->arr[i].~Accet();
        }
        free(this->arr);
        this->length = 0;
        this->size = 0;
        this->arr = nullptr;
    }
    void Add(const Accet& aa) {
        if (this->length >= this->size) {
            return ;
        }

        new(this->arr + this->length)Accet(aa);
        (this->length)++;
        return ;
    }
};

Accet func() {
    Accet a0;
    return a0;
}

int main() {
    Testt t1;
    Accet a1;
    t1.Add(a1);
    t1.Add(func());
    t1.Add(func());
    t1.Add(func());
    Testt t2(t1);
    
    
    
    return 0;
}