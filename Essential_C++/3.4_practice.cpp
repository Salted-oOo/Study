/*
* @Author: salted_fish
* @Date:   2018-01-05 13:52:28
* @Last Modified by:   salted_fish
* @Last Modified time: 2018-01-05 16:04:06
*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main() {
	int ia1[7] = {1, 1, 2, 3, 5, 55, 89};
	int ia2[4] = {8, 13, 21, 34};
	list<int> elems(ia1, ia1 + 7);

	list<int>::iterator it = find(elems.begin(), elems.end(), 55);
	elems.insert(it, ia2, ia2 + 4);

	list<int>::iterator iter = elems.begin();
	while (iter != elems.end()) {
		cout << *iter << endl;
		iter++;
	}
	return 0;
}


