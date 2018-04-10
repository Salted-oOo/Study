#include <stdio.h>

//#define MAX_N 10
#define MAX_N 30

int ans[10] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};

//int roe_vaild[MAX_N] = {0};
//int col_vaild[MAX_N] = {0};
//int martix[MAX_N][MAX_N] = {0};

int col_vaild[MAX_N] = {0};
int v1_valid[MAX_N] = {0};
int v2_valid[MAX_N] ={0};

int plan(int i, int n) {
    if (i == n) {
        return 1;
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (col_vaild[j]) continue;
        if (v1_valid[i + j]) continue;
        if (v2_valid[n - i + j]) continue;
        col_vaild[j] = 1;
        v1_valid[i + j] = 1;
        v2_valid[n - i + j] = 1;
        ans += plan(i + 1, n);
        col_vaild[j] = 0;
        v1_valid[i + j] = 0;
        v2_valid[n - i + j] = 0;
    }
    return ans;
}

/* int plan(int i, int j, int n) {
    if (i == n) {
        return 1;
    }
    row_valid[i] = 1;
    col_vaild[j] = 1;
    matrix[i][j] = 1;
    int ans = 0;
    for (int col = 0; col < n; col++) {
        if (col_vaild[col]) continue;
        int x = i + 1, y = col;
        do {
            x -= 1; y -= 1;
            if (x < 0 || y < 0) break;
            if (martix[x][y]) break;
        } while(1);
        if (x >= 0 && y >= 0) continue;
        x = i + 1, y = col;
        do  {
            x -= 1; y += 1;
            if (x < 0 || y >= n) break;
            if (martix[x][y]) break;
        } while(1);
        if (x >= 0 && y < n) continue;
        ans += plan(i + 1, col, n);
    }
    row_valid[i] = 0;
    col_vaild[j] = 0;
    matrix[i][j] = 0;
    return ans;
}
*/


int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if (n == 0) break;
        printf("%d\n", ans[n - 1]);
    }
    //for(int i = 1; i <= 10; i++) {
        //printf("%d\n", plan(0, i));
    //}
    return 0;
}
