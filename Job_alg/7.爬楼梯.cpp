#include <stdio.h>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int f[4] = {1, 0, 1, 1};
		if (n < 4) {
			printf("%d\n", f[n]);
			continue;
		}
		for (int i = 4; i <= n; i++) {
			f[i % 4] = f[(i - 2) % 4] + f[(i - 3) % 4];
		}
		printf("%d\n", f[n % 4]);
	}
	return 0;
}