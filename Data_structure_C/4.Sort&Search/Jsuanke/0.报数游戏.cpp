#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int left, int right) {
    if (left > right) {
        return ;
    }
    int pivot = arr[left], low = left, high = right;
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    quick_sort(arr, left, low - 1);
    quick_sort(arr, low + 1, right);
}

int serch(int *arr, int n, int value) {
    int head = 0, tail = n - 1;
    int mid;
    while (head < tail) {
        mid = (head + tail + 1) / 2;
        if (arr[mid] == value) {
        	return arr[mid];
        } else if (arr[mid] > value) {
            tail = mid - 1;
        } else {
            head = mid;
        }
    }
    return arr[head];
}


int main() {
	int n, m, a, ans;
	scanf("%d%d", &n, &m);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	quick_sort(arr, 0, n - 1);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		ans = serch(arr, n, a);
		if (i == m - 1) {
			printf("%d\n", ans);
			break;
		}
		printf("%d ", ans);
	}
    free(arr);
	return 0;
}