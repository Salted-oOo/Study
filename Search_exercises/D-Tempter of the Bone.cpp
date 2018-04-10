#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10
int N, M, T, flag = 0;
char map[MAX_N][MAX_N];
int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};

typedef struct Graph {
    int mat[MAX_N][MAX_N];
    int n, m;
} Graph;

void init_graph(Graph *g, int n, int m) {
    g->n = n;
    g->m = m;
    memset(g->mat, 0, sizeof(g->mat));
}

void DFS(Graph *g, int tem_i, int tem_j, int T) {
    if (flag == 1 || !T) return ;
    int indx, indy;
    g->mat[tem_i][tem_j] = 1;
    for (int i = 0; i < 4 && flag == 0; i++) {
        indx = tem_i + dir[i][0];
        indy = tem_j + dir[i][1];
        if (indx < 0 || indx >= N) continue;
        if (indy < 0 || indy >= M) continue;
        if (g->mat[indx][indy] == 1) continue;
        if (map[indx][indy] == 'X') continue;
        if (map[indx][indy] == 'D') {
            flag = (T == 1);
            continue;
        }
        //printf("%d %d\n", indx, indy);
        DFS(g, indx, indy, T - 1);
    }
    g->mat[tem_i][tem_j] = 0;
    return ;
}


int main() {
    int tem_i, tem_j;
    tem_i = tem_j = 0;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    while(scanf("%d%d%d", &N, &M, &T) != EOF) {
        getchar();
        if (N == 0 && M == 0 && T == 0) break;
        init_graph(g, N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'S'){
                    tem_i = i;
                    tem_j = j;
                    g->mat[i][j] = 1;
                }
            }
            getchar();
        }
    /*    for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                    printf("%c", map[i][j]);
                }
            }
    */
        DFS(g, tem_i, tem_j, T);
        printf("%s\n", flag == 1 ? "YES" : "NO");
    }
    free(g);
    return 0;
}
