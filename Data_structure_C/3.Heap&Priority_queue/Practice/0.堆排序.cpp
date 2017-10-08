#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {  \
	__typeof(a) __temp = (a);  \
	(a) = (b); (b) = __temp;  \
}



void heap_sort(int *arr, int n) {
	for (int i = 1; i < n; i++) {
		int current = i;
		int father = (current - 1) / 2;
		while (arr[current] > arr[father]){
			swap(arr[current], arr[father]);
			current = father;
			father = (current - 1) / 2;
		}
	}
	for (int i = n -1; i >= 1; --i) {
		swap(arr[i], arr[0]);
		int lchild, rchild, max_index = 0;
		while (true) {
			lchild = 2 * max_index + 1;
			rchild = 2 * max_index + 2;
			if (lchild < i && arr[lchild] > arr[max_index]) {
				max_index = lchild;
			}
			if (rchild < i && arr[rchild] > arr[max_index]) {
				max_index = rchild;
			}
			if (max_index == rchild || max_index == lchild) {
				swap(arr[max_index], arr[(max_index - 1) / 2]);
			} else {
				break;
			}
		}
	}
	return ;
}

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	heap_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}