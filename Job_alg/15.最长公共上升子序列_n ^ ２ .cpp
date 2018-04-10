#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int lengthOfLICS(int *nums1, int length1, int *nums2, int length2) {
    int *dp[2];
    dp[0] = (int *)calloc(length2 + 1, sizeof(int));
    dp[1] = (int *)calloc(length2 + 1, sizeof(int));
    int ans = 0, k_max;
    for (int i = 0; i < length1; i++) {
        k_max = 0;
        for (int j = 0; j < length2; j++) {
            if (nums1[i] > nums2[j] && dp[!(i & 1)][j + 1] > k_max) {
                k_max = dp[!(i & 1)][j + 1];
            }
            if (nums1[i] != nums2[j]) {
                dp[i & 1][j + 1] = dp[!(i & 1)][j + 1];
            } else {
                dp[i & 1][j + 1] = k_max + 1;
                if (ans < k_max + 1) ans = k_max + 1;
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