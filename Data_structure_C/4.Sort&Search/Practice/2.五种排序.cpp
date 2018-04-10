#include <stdio.h>
#include <stdlib.h>

	
#define swap(a, b) { \
	__typeof(a) __temp = (a); \
	(a) = (b); (b) = __temp; \
}

typedef struct Data {
	int val, index;
} Data;

int cmp_data(Data a, Data b) {
	if (a.val > b.val) return 1;
	if (a.val == b.val && a.index < b.index) return 1;
	return 0;
}

void insert_sort(Data *arr, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 1; --j) {
			if (cmp_data(arr[j], arr[j])) {
				swap(arr[j], arr[j - 1]);
			} else {
				break;
			}
		}
	}
	return ;
}

void bubble_sort(Data *arr, int n) {
	int times = 1;
	for (int i = n - 1; i >= 1 && times; i--) {
		times = 0;
		for (int j = 0; j < i; j++) {
			if (cmp_data(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
				times++;
			}
		}
	}
	return ;
}

void merge_sort(Data *arr, int l, int r) {
	if (r < l) return ;
	if (r == l) return ;
	if (r - l == 1) {
		if (cmp_data(arr[r], arr[l])) {
			swap(arr[r], arr[l]);
		}
		return ;
	}
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	Data *temp = (Data *)malloc(sizeof(Data) * (r - l + 1));

	int ind1 = l, ind2 = mid + 1, k = 0;
	while (ind1 <= mid || ind2 <= r) {
		if (ind2 > r) {
			temp[k++] = arr[ind1++];
		} else if (ind1 > mid) {
			temp[k++] = arr[ind2++];
		} else if (cmp_data(arr[ind2], arr[ind1])) {
			temp[k++] = arr[ind2++];
		} else {
			temp[k++] = arr[ind1++];
		}
	}

	for (int i = l; i < r; i++) {
		arr[i] = temp[i - l];
	}
	free(temp);
}

void select_sort(Data *arr, int n) {
	int min_index;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (cmp_data(arr[j], arr[min_index])) {
				k = j;
			}
		}
	}
}

void quick_sort(Data *arr, int l, int r) {
	if (r <= l) return ;
	int x = l, y = r;
	Data z = arr[0];
	while (x < y) {
		while (x < y && cmp_data(z, arr[y])) --y;
		if (x < y) arr[x++] = arr[y];
		while (x < y && cmp_data(arr[x], z)) ++x;
		if (x < y) arr[y--] = arr[x];
	}
	arr[x] = z;
	quick_sort(arr, l, x - 1);
	quick_sort(arr, x + 1, r);
}


void output(Data *arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d(%d) ", arr[i].val, arr[i].index);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	Data *arr = (Data *)malloc(sizeof(Data) * n); 
	for (int i = 0; i < n; ++i) {
		scanf("%d(%d)", &arr[i].val, &arr[i].index);

	}
	insert_sort(arr, n);
	output(arr, n);
	bubble_sort(arr, n);
	output(arr, n);
	merge_sort(arr, 0, n - 1);
	output(arr, n);
	free(arr);
	return 0;
}















