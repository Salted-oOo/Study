#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <unistd.h>
#include <iomanip>
#include "pic1.h"
#include "pic2.h"
#include "pic3.h"
using namespace std;
   
template<typename T>
class Vector {
    public:
   Vector(int size) {
       this->data = new T[size];
       this->size = size;
       this->flag = 1;
       this->length = 0;
   }
   T& operator[](const int ind) {   
       if (ind < 0 || ind >= this->size) {
                std::cout << "\033[01;31mmsegment fault ! but I am xiaoqiang !\033[0m" << std::endl;
           system("say A little warning");
           return this->nil;
       } else {
           return this->data[ind];
       }
   }

  void expand() {
    this->size *= 2;
    T *ndata = new T[this->size];
    for(int i = 0; i <= this->size; i++) {
      ndata[i] = this->data[i];
    }
    this->data = ndata;
    return ;
  }

  void insert(int index, T value) {
    if(index < 0 || index > this->length) {  
      cout << "\033[01;31mno\033[0m" << endl;
      system("say oh my dear This position is illegal");
      return ;
    }
    if(this->length >= this->size) {
      expand();
    }
    for(int i = this->length; i > index; --i) {
      data[i] = data[i - 1];
    }
    data[index] = value;
    this->length++;
    return ;
  }

  void delete_node(int index) {
    if(index < 0 || index > this->length) {
      cout << "\033[01;31mno\033[0m" << endl;
       system("say oh my dear This position is illegal");    
      return;
    }
    for(int i = index; i < this->length - 1; i++) {
      data[i] = data[i + 1];
    }
    this->length--;
    return;
  }

    void _output() {
        cout.setf(std::ios::left);
        
        if(this->flag == 2) {
    for(int i = 0; i < this->length;i++) {
            cout.setf(std::ios::left);
            cout << "   |                  |" << endl;
            cout << "   |                  |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |_______________|__|" << endl;
            cout << "| /                |  /" << endl;
            if(i < this->length)
            cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i]<<right<<setw(5)<<" "<<"| /|"<<endl;
            else
            cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /|"<<endl;
                cout << "|__________________|/ |" << endl;
                cout << "|  |               |  |" << endl;
                cout << "|  |               |  |" << endl;
                cout << "|  |               |  |" << endl;
                cout << "|  |               |  |" << endl;
                cout << "|  |_______________|__|" << endl;
                cout << "| /                |  /" << endl;
            if(i + 1 < this->length)
            cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i + 1]<<right<<setw(5)<<" "<<"| /|"<<endl;
            else
            cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /|"<<endl;
            cout << "|__________________|/ |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |               |  |" << endl;
            cout << "|  |_______________|__|" << endl;
            cout << "| /                |  /" << endl;
    if(i + 2 < this->length)
        cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i + 2]<<right<<setw(5)<<" "<<"| /|"<<endl;
    else
        cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /|"<<endl;
    cout << "|__________________|/ |" << endl;
    cout << "|  |               |  |" << endl;
    cout << "|  |               |  |" << endl;
    cout << "|  |               |  |" << endl;
    cout << "|  |               |  |" << endl;
    cout << "|  |_______________|__|" << endl;
    cout << "| /                |  /" << endl;
    if(i + 3 < this->length)
        cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i + 3]<<right<<setw(5)<<" "<<"| /"<<endl;
    else
        cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /"<<endl;
    cout << "|__________________|/" << endl;
    if(i > this->length) break;
    usleep(1000000);
    system("clear");
    usleep(100000);
    

        }
        }
        else 
        for(int i = 0; i < length; i++) {
            cout << "   |                  |" << "  ";cout << "   |                  |";
            cout << "    |                  |" << "  ";cout << "   |                  |" << endl;
            cout << "   |                  |" << "  ";cout << "   |                  |";
            cout << "    |                  |" << "  ";cout << "   |                  |" << endl;
            cout << "|  |               |  |" << "  ";cout << "|  |               |  |";
            cout << " |  |               |  |" << "  ";cout << "|  |               |  |" << endl;
            cout << "|  |               |  |" << "  ";cout << "|  |               |  |";
            cout << " |  |               |  |" << "  ";cout << "|  |               |  |" << endl;
            cout << "|  |_______________|__|" << "  ";cout << "|  |_______________|__|";
            cout << " |  |_______________|__|" << "  ";cout << "|  |_______________|__|" << endl;
            cout << "| /                |  /" << "  ";cout << "| /                |  /";
            cout << " | /                |  /" << "  ";cout << "| /                |  /" << endl;
            if(i < this->length)
                cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i]<<right<<setw(5)<<" "<<"| /"<< "  ";
            else
                cout<<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /"<< "  ";
            if(i + 1 < this->length)
                cout<< " " <<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i+1]<<right<<setw(5)<<" "<<"| /";
            else
                cout<< " " <<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /";
            if(i + 2 < this->length)
                cout<<"  |/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i+2]<<right<<setw(5)<<" "<<"| /"<< "  ";
            else
                cout<<"  |/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /"<< "  ";
            if(i + 3 < this->length)
                cout<< " " <<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<data[i+3]<<right<<setw(5)<<" "<<"| /"<<endl;
            else
                cout<< " " <<"|/"<<left<<setw(4)<<" "<<left<<setw(8)<<"xxxx"<<right<<setw(5)<<" "<<"| /"<<endl;
            cout << "|__________________|/" << "  "; cout << "  " << "|__________________|/";
            cout << "   |__________________|/" << "  "; cout << "  " << "|__________________|/" << endl;
            if(i >= this->length) break;
            usleep(1000000);
            system("clear");
            usleep(100000);
        }
    }






  void find(T arr) {
    for(int i = 0; i < this->length; i++) {
      if(data[i] == arr) {
        printf("This postion is %d\n", i);
          return ;
      }
    }
      cout << "\033[01;31mno\033[0m" << endl; 
      system("say oh my dear i am not find it Forgive me");
    return ;
  }

  void push(T value) {
    switch(this->flag) {
        case 1:cout << "\033[01;31mOH boy I am vector can not pushed\033[0m" << endl;  system("say You stupid jerk"); break;
      default : {
        data[this->length++] = value;
      }
    }
  }

  void pop() {
    switch(this->flag) {
      case 1:cout << "\033[01;31mOH boy I am vector can not pop\033[0m" << endl; system("say You stupid jerk"); break;
      case 2:{
        this->length--;
      }
      case 3:{
        this->delete_node(0);
      }
    }
  }

  void top() {
    if(this->flag == 2) {
      std::cout << data[this->length - 1] << std::endl;
    } else {
      cout << "\033[01;31mOH boy I am not a stack can not top\033[0m" << endl; 
      system("say Please, I can not do it");
    }
  }

  void front() {
    if(this->flag == 3) {
      std::cout << data[0] << std::endl;
    } else {
      cout << "\033[01;31mOH boy I am not a queue can not front\033[0m" << endl; 
      system("say Please, I can not do it");
    }
  }

  void duang() {
    switch(this->flag) {
      case 1:{
        this->flag = 2;
        cout << "\033[01;31mOH baby I am a stack now\033[0m" << endl;

        system("say ba la la neng liang wo yao bian sheni");
          break;
      }
      case 2:{
        this->flag = 3;
        cout << "\033[01;31mOH baby I am a queue now\033[0m" << endl;
        system("say ba la la neng liang wo yao bian sheni");
        break;
      }
      case 3:{
        this->flag = 1;
        cout << "\033[01;31mOH baby I am a vector now\033[0m" << endl;
        system("say ba la la neng liang wo yao bian sheni");
        break;
      }
    }
  }

   T nil;
   T *data;
   int size;
   int length;
   int flag; //1是线性表  2是栈   3是队列
};
int main() {


    while(1) {
        std::cout << " \033[01;36m/****************************************************************************************************************\033[0m<" << std::endl;
        std::cout << " \033[01;34m>    This is a sequential table that can store any type, but we add a few other features for users to use       \033[0m<" << std::endl;
        std::cout << " \033[01;34m>  Operation of Vector : insert(index, value) delete_node(index) output() find(value)                           \033[0m<" << std::endl;
        std::cout << " \033[01;34m>  Operation of duang  : This operation allows Vector to be either a stack or a queue, just call it             \033[0m<" << std::endl;
        std::cout << " \033[01;34m>  Operation of queue  : push(value) pop() front()                                                              \033[0m<" << std::endl;
        std::cout << " \033[01;34m>  Operation of stack  : push(value) pop() top()                                                                \033[0m<" << std::endl;
        std::cout << " \033[01;34m>  input exit Finish this program and input quit Finish this Vector                                             \033[0m<" << std::endl;
        std::cout << " \033[01;36m****************************************************************************************************************/\033[0m<" << std::endl;
        
        Vector<int> a(100);
        int _pos, _val;
        std::string str;

        while(1) {
            printf("Please input your command\n");
            std::cin >> str;
            if(str == "insert") {
                std::cin >> _pos >> _val;
                a.insert(_pos, _val);
            } else if(str == "delete_node") {
                std::cin >> _pos;
                a.delete_node(_pos);
            } else if(str == "output") {
                a._output();
            } else if(str == "find") {
                std::cin >> _pos;
                a.find(_pos);
            } else if(str == "duang") {
                a.duang();
            } else if(str == "pop") {
                a.pop();
            } else if(str == "push") {
                std::cin >> _val;
                a.push(_val);
            } else if(str == "front") {
                a.front();
            } else if(str == "top") {
                a.top();
            } else if(str == "exit") {
                outout2();
                return 0;
            } else if(str == "quit") {
                outout1();
                break;
            } else if(str == "kuxuan") {
                boss();
            } else {
                printf("The input is not valid. Please re-enter it\n");
            }
        }
    }
   return 0;
}



