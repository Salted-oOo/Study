#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char map[10][10];
int visit[10][10];
int n,m,t,ex,ey,flag;

void dfs(int sx,int sy,int step) {
    int i,dx,dy;
    int next[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    if(flag) return;
    if(sx == ex && sy == ey && step == t) {
        flag=1;
        return ;
    }
    int tem = t - step - (abs(ex - sx) + abs(ey - sy));
    if(tem < 0 || tem & 1) return;
    for(i = 0; i < 4; i++) {
        dx = sx + next[i][0];
        dy = sy + next[i][1];
        if(dx < 0 || dy >= m || dy < 0 || dx >= n) continue;
        if(map[dx][dy] != 'X' && visit[dx][dy] == 0) {
            visit[dx][dy] = 1;
            dfs(dx, dy, step+1);
            if(flag) return;
            visit[dx][dy] = 0;
        }
    }
    return ;
}

int main() {
    int i, j;
    int sx, sy;
    while(~scanf("%d%d%d",&n, &m, &t)) {
        if(n == 0 && m == 0 && t == 0) break;
        flag = 0;
        memset(visit, 0, sizeof(visit));
        for(i = 0; i < n; i++) {
            scanf("%s", map[i]);
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(map[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if(map[i][j] == 'D') {
                    ex = i;
                    ey = j;
                }
            }
        }
        visit[sx][sy] = 1;
        dfs(sx, sy, 0);
        printf("%s\n", flag == 1 ? "YES" : "NO");
    }
    return 0;
}
