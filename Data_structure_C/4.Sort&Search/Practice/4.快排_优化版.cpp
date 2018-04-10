#include <iostream>
#include <cstdio>
using namespace std;

void quick_sort(int *arr, int left, int right) {
    while (left < right) {
        int x, y, z;
        x = left, y = right;
        z = arr[(left + right) >> 1];
        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while(x <= y);
        quick_sort(arr, left, y);
        left = x;
    }
    return ;    
} 

int main() {
    int n;
    cin >> n;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    quick_sort(arr, 0, n - 1);
    printf("%d", arr[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", arr[i]);
    }
    cout << endl;
    return 0;
}