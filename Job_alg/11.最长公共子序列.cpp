#include <stdio.h>
#include <stdlib.h>
int lengthOfLCS(char *str1, char *str2) {
	int len1 = strlen(str1), len2 = strlen(str2);
	int dp[2][2];
	for (int i = 0; i < len1; i++) {
		dp[i & 1][1] = 0;
		for (int j = 0; j < len2; j++) {
			dp[i & 1][j & 1] = dp[!(i & 1)][j & 1];
			if (dp[i & 1][!(j & 1)] > dp[i & 1][j & 1]) {
				dp[i & 1][j & 1] = dp[i & 1][!(j & 1)];
			}
		if (str1[i] == str2[j] && dp[!(i & 1)][!(j & 1)] + 1 > dp[i & 1][j & 1] )
			dp[i & 1][j & 1] = dp[!(i & 1)][!(j & 1)] + 1;
		}
	}
	return dp

}
int main() {
	char a[1000+10];
	char b[1000+10];
	scanf("%s %s", a, b);
	printf("%d\n", lengthOfLCS(a, b));
}