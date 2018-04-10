#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int *data, int left, int right) {
    if (left > right) {
        return ;
    }
    int pivot = data[left], low = left, high = right;
    while (low < high) {
        while (low < high && data[high] >= pivot) {
            high--;
        }
        data[low] = data[high];
        while (low < high && data[low] <= pivot) {
            low++;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    quick_sort(data, left, low - 1);
    quick_sort(data, low + 1, right);
}

int main() {
    int n;
    int arr[n + 10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", arr[i]);
    }
    return 0;
}