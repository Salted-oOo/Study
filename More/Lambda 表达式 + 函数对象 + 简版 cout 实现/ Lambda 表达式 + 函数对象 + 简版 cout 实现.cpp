#include <iostream>
#include <functional>
#include <ctime>
using namespace std;
 
namespace haizei {
class ostream;
 
auto insert_sort = [](int *num, int n) {
    if (n <= 1) return ;
    for (int i = 1; i < n; i++) {
        if (num[i] < num[0]) {
            swap(num[i], num[0]);
        }
    }
    for (int i = 2; i < n; i++) {
        int j = i;
        while (num[j] < num[j - 1]) {
            swap(num[j], num[j - 1]);
            j--;
        }
    }
};
 
class my_sort {
public :
    my_sort() : threthold(16) {}
    my_sort(int x) : threthold(x) {}
    void set_threthold(int x) {
        this->threthold = x;
    }
    void operator()(int *num, int n) {
        cout << "sort : " << this->threthold << endl;
        this->__sort(num, 0, n - 1);
    }
    friend ostream &operator<<(ostream &out, my_sort &a);
private :
    int threthold;
    void __sort(int *num, int left, int right) {
        while (left < right) {
            if (right - left < threthold) {
                insert_sort(num + left, right - left + 1);
                return ;
            }
            int x, y, z;
            x = left, y = right, z = num[left];
            while (x < y) {
                while (x < y && num[y] >= z) y--;
                if (x < y) num[x++] = num[y];
                while (x < y && num[x] <= z) x++;
                if (x < y) num[y--] = num[x];
            }
            num[x] = z;
            this->__sort(num, x + 1, right);
            right = x - 1;
        }
        return ;
    }
};
 
class Precision {
public :
    Precision(int x) : precision(x) {}
    int precision;
};

class length {
public :
    length(int x) : length(x) {}
    int length;
}
 
class ostream {
public :
    ostream() = default;
    
    ostream &operator <<(const int x) {
        int 
        this->__Print("%d", x);
        return *this;
    }
    ostream &operator <<(const double x) {
        char fmt[15];
        sprintf(fmt, "%%.%dlf", this->__precision);
        this->__Print(fmt, x);
        return *this;
    }
    ostream &operator <<(const char *str) {
        this->__Print("%s", str);
        return *this;
    }
    ostream &operator <<(const Precision &a) {
        this->__precision = a.precision;
        return *this;
    ostream &operator <<(const length &a) {
        this->__length = a.length;
        return *this;
    }
private :
    int __precision;
    template<typename T>
    void __Print(const char *fmt, T &x) {
        printf(fmt, x);
        return ;
    }
    int __length;
    template<typename T>
    void __Print(const int zero, T &x) {
        for(int i = 0; i < zero; i++)
            printf(" ", x);
        return ;
    }
};
 
auto sort = my_sort();
auto cout = ostream();
auto endl = "\n";
 
ostream &operator<<(ostream &out, my_sort &a) {
    out << "my threthold is : " << a.threthold << endl;
    return out;
}
 
}; // end of haizei namespace
 
void rand_value(int *num, int n) {
    while (n--) {
        num[n] = rand() % 100;
    }
}
 
void output(int *num, int n) {
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
 
struct Point {
    int x, y;
};
 
haizei::ostream &operator<<(haizei::ostream &out, Point &a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}
 
int main() {
    
    srand(time(0));
    int arr[100];
    
    rand_value(arr, 100);
    haizei::sort(arr, 100);
    output(arr, 100);
    Point p1 = {1, 2};
    Point p2 = {4, 7};
    Point p3 = {10, 96};
    haizei::cout << haizei::Precision(3) << 4.567893 << haizei::endl;
    haizei::cout << 
    haizei::cout << "haizei : " << 731 << haizei::endl << haizei::sort << haizei::endl;
    haizei::cout << "p1 : " << p1 << haizei::endl;
    haizei::cout << "p2 : " << p2 << haizei::endl;
    haizei::cout << "p3 : " << p3 << haizei::endl;
    haizei::sort.set_threthold(1);
    rand_value(arr, 100);
    haizei::sort(arr, 100);
    output(arr, 100);
    
    haizei::sort.set_threthold(32);
    rand_value(arr, 100);
    haizei::sort(arr, 100);
    output(arr, 100);
    
    return 0;
}