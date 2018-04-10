#include <stdio.h>
#include <stdlib.h>ｋｋｋｋｋｋｋｋ
int find_max(int *data, int length) {
    int left = 0, right = length - 1;
    int count = 0;
    while (right - left >= 2) {
        count++;
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left + 2) / 3;
        if (data[m1] < data[m2]) {
            right = m2;
        } else {
            left = m1 + 1;
        }
    }
    if (data[right] < data[left]) {
        printf("%d %d\n", count, right);
        return 0;
    } else {
        printf("%d %d\n", count, left);
        return 0;
    }
}

int main() {
    double a, b, c;
    scanf("%lf%lf%lf", &a, );
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    find_max(arr, n);
    return 0;
}