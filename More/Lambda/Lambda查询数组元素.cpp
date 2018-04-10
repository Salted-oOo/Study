#include <iostream>
#include <string>
#include <functional>
using namespace std;


auto cmp_function =[](int value, function<bool(int&,int&> cmp) {
	return[=](int *num, int n){
		int ans = value;
		for (int i = 0; i < n; i++) {
			if (cmp(num[i], ans)) ans = num[i];
		}
		return ans;
	};
};

auto find_min = cmp_function(INT_MAX, [](int &a, int &b){return a < b;});
auto find_max = cmp_function(INT_MIN, [](int &a, int &b){return a > b;});

auto find = [](int ret_value, int find_num) {
	return cmp_function(ret_value, [=](int &a, int &b){return (a == find_num);});
};

/*int find_min(int *num, int n) {
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (num[i] < ans) ans = num[i];
	}
	return ans;
}

int find_max(int *num, int n) {
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (num[i] > ans) ans = num[i];
	}
	return ans;
}
*/


int mian() {
	int arr[20] = {1, 2, 3, 4, 10, 5, 6, 7, 8, 9};
	cout << find_min(arr, 10) << endl;
	cout << find_max(arr, 10) << endl;
	cout << find(-1, 9)(arr, 10) << endl;
	cout << find(-1, 12)(arr, 10) << endl;
	return 0;
}