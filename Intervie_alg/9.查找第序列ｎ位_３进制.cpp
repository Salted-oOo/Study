#include <iostream>
#include <algorithm>
#include <string>
#include <cmath> // pow(x, y)
using namespace std;

//int bit_nums[10] = {0,3 9 27 81 2 43}
int bit_nums[16];
int ten_to_three[30] = {0};

void get_bit_nums() {
	bit_nums[0] = 0;
	for(int i = 1, j = 1; i <= 15; i++, j++) {
		if (i == 1) {
	        bit_nums[i] = 3; continue;
		}
		bit_nums[i] = bit_nums[i- 1] + ((int)pow(3, i) - (int)pow(3, i - 1)) * j;
		cout << bit_nums[i] << " " ;
		cout << endl                                                                                     ; 
	}
	return ; 
}

void search_bit(int n) {
	int i = 1, range = 0, offset, offset_rem, offset_int, ans_ten, ans; //偏移量
	while(n > bit_nums[i]) {
		range = i;
		i++;
	}
	range = range + 1;  //位数
	offset = n - bit_nums[i - 1];  //偏移量
	offset_rem =  offset % range;  //余数
	offset_int =  (offset - 1)/ range;  //第几位数
	ans_ten = (int)pow(3, range - 1) + offset_int; //从０开始

	cout << endl << "range is ->" << range << endl
		 << "i is->" << i << endl
		 << "n is->" << n << endl
		 << "bit_nums[n - 1] is ->" << bit_nums[i - 1] << endl
		 << "offset is->" << offset << endl
		 << "offset_rem is->" << offset_rem << endl
		 << "offset_int is->" << offset_int << endl
		 << "ans_ten is ->" << ans_ten << endl;


    int temp, j = 1, count;
    temp = ans_ten;  
    count = temp;
    while(count) {
        count /= 3;
        ten_to_three[j++] = temp - 3 * count;
        temp = count;
    }



    ans = ten_to_three[range - offset_rem] + 1;


    for(int i = 0; i < 20; i++) {
    	cout << ten_to_three[i] << " " ;
    }
    cout <<  endl << "The ans is : " << ans << endl;

	//while (n > (int)pow(3, i)) i++;
	//offset = n - bit_nums[i - 1];
	//offset_bit = offset % i;


	// cout << range << endl;
	//cout << "i is : " << i << endl
	// 	 << "the bit_nums[" << i - 1 << "] is : " << bit_nums[i - 1] << endl
	//	 << "the offset is :　" << offset << endl;
}

int main() {
	int n;
	cin >> n;
	get_bit_nums();
	search_bit(n);`
	return 0;
}