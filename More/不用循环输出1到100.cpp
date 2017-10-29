/*
* @Author: alivedreams
* @Date:   2017-10-25 18:49:51
* @Last Modified by:   alivedreams
* @Last Modified time: 2017-10-25 18:53:27
*/
#include <iostream>
using namespace std;
int main(int i, char *argc[]) {
	cout << i << endl;
	if (i == 100) return 0;
	return main(i + 1, NULL);
}