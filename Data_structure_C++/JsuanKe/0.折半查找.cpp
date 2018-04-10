#include <iostream>
using namespace std;

int search(int *nums, int n, int index) {
    int head = 0;
    int tail = n - 1;
    int mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] == index) {
            return mid + 1;
        } else if (nums[mid] > index) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return 0;
}

int main() {
    int n, m, k, ans;
    int nums[1000010];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    cout << search(nums, n, k);
    for (int i = 1; i < m; i++) {
        cin >> k;
        cout << " " << search(nums, n, k);
    }
    return 0;
}