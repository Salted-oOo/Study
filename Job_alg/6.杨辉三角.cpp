#include <stdio.h>
long long PascalTriangle(int row, int column) {
    int num[100][100];
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99; j++) {
            num[i][j] = 0;
        }
    }
    num[0][1] = 1; 
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] = num[i - 1][j] + num[i - 1][j - 1]; 
        }
    }
    return num[row][column];
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", PascalTriangle(n, m));
	return 0;
}