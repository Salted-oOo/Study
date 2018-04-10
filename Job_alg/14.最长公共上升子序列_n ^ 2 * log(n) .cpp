#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits.h>
using namespace std;
 
int binary_search(int *nums, int n, int x) {
    int head, tail, mid;
    head = 0, tail = n - 1;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] >= x) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }
    return head;
}
 
int lengthOfLICS(int *nums1, int length1, int *nums2, int length2) {
    int *dp[2];
    int *len = (int *)calloc(length2 + 1, sizeof(int));
    dp[0] = (int *)calloc(length2 + 1, sizeof(int));
    dp[1] = (int *)calloc(length2 + 1, sizeof(int));
    int ans = 0;
    for (int i = 0; i < length1; i++) {
        len[0] = INT_MIN;
        for (int j = 0; j < length2; j++) {
            len[j + 1] = INT_MAX;
            int ind = binary_search(len, j + 2, nums2[j]);
            if (nums1[i] != nums2[j]) {
                if (nums2[j] < len[dp[!(i & 1)][j + 1]]) {
                    len[dp[!(i & 1)][j + 1]] = nums2[j];
                }
                dp[i & 1][j + 1] = dp[!(i & 1)][j + 1];
            } else {
                dp[i & 1][j + 1] = ind;
                len[ind] = nums2[j];
                if (dp[i & 1][j + 1] > ans) ans = dp[i & 1][j + 1];
            }
        }
    }
    return ans;
}
int main() {
	vector<int> a, b;
	int n, m, d;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> d;
		a.push_back(d);
	}
	for (int j = 0; j < m; ++j) {
		cin >> d;
		b.push_back(d);
	}
	cout << lengthOfLICS(a, b) << endl;
	return 0;
}