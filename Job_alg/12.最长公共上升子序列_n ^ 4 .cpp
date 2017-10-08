#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int lengthOfLICS(int *nums1, int length1, int *nums2, int length2) {
    int **dp = (int **)calloc(length1 + 1, sizeof(int *));
    int i, j, k, l;
    for (i = 0; i < length1; ++i) {
        dp[i] = (int *)calloc(length2 + 1, sizeof(int));
    }
    int ans = 0;
    for (i = 0; i < length1; ++i) {
        for (j = 0; j < length2; ++j) {
            if (nums1[i] == nums2[j]) {
                dp[i][j] = 1;
                for (k = 0; k < i; ++k) {
                    for (l = 0; l < j; ++l) {
                        if (nums1[k] != nums2[l]) continue;
                        if (nums1[k] >= nums1[i]) continue;
                        if (dp[k][l] + 1 <= dp[i][j]) continue;
                        dp[i][j] = dp[k][l] + 1;
                    }
                }
                if (dp[i][j] > ans) ans = dp[i][j]; 
            } else {
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < length1; ++i) {
        free(dp[i]);
    }
    free(dp);
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