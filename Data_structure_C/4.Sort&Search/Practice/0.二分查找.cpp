#include <stdio.h>

int binary_search(int *arr, int n, int value) {
	int head = 0, tail = n - 1;
	int mid;
	while (head < tail) {
		mid = (head + tail) / 2;
		if (arr[mid] == value) {
			tail = mid;
		} else if (arr[mid] < value) {
			head = mid + 1;
		} else {
			head = mid - 1;
		}
	} 
	return arr[head] == value ? head : -1;
}



int main() {
	int arr[100] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
	int n, index, ret;
	while (scanf("%d" ,&n) != EOF) {
		index = binary_search(arr, 10, n);
		printf("%d\n", index);
		//ret = 0;
/*		for (int i = 0; i < 10; i++) {
			if (i <= index) {
				ret +=printf("%5d", arr[i]);
			} else {
				printf("%5d", arr[i]);
			}
		}
		printf("\n");
		ret1 = ret;
		while (ret1 && )
		while (--ret) {
			printf(" ");
		}
		printf("|\n\n");

*/

	}
	return 0;
}