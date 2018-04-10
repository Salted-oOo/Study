#include <stdio.h>
long long paintWallCounts(int wallsize) {
	if (wallsize == 1) return 3;
    long long dp[2][3][3] = {0};
    dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
    for (int n = 2; n <= wallsize; n++) {
    	for (int i = 0; i < 3; i++) {
    		for (int j = 0; j < 3; j++) {
    			dp[n % 2][i][j] = 0;
    			for (int k = 0; k < 3; k++) {
    				if (k == j) continue;
    				dp[n % 2][i][j] += dp[!(n & 1)][i][k];
    			}
    		}
    	}
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 3; j++) {
    		if (i == j) continue;
    		ans += dp[wallsize & 1][i][j];
    	}
    }
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", paintWallCounts(n));
    return 0;
}