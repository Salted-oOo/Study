/*
* @Author: alivedreams
* @Date:   2017-10-25 17:25:01
* @Last Modified by:   alivedreams
* @Last Modified time: 2017-10-25 17:48:22
*/
//% PRId8    PRIu8   int8_t   uint8_t
//% PRId16   PRIu16  int16_t  uint16_t
#include <iostream>
#include <cinttypes>
using namespace std;

int func1(uint32_t x) {
	x = (x & 0x55555555) + ((x & 0xAAAAAAAA) >> 1);
	x = (x & 0x33333333) + ((x & 0xCCCCCCCC) >> 2);
	x = (x & 0x0F0F0F0F) + ((x & 0xF0F0F0F0) >> 4);	
	x = (x & 0x00FF00FF) + ((x & 0xFF00FF00) >> 8);
	x = (x & 0x0000FFFF) + ((x & 0xFFFF0000) >> 16);
	return x;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d has %d one\n", n, func1(n));
	}
	return 0;
}