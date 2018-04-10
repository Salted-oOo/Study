#include <stdio.h>
#include <stdlib.h>
typedef struct UnionSet {
    int *color;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet) * 1);
    p->n = n;
    p->color = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        p->color[i] = i;
    }
    return p;
}

void clear(UnionSet *u) {
    free(u->color);
    free(u);
}

int find(UnionSet *u, int ind){
    return u->color[ind];
}

int merge(UnionSet *u, int p, int q) {
    int color_p, color_q;
    color_p = find(u, p);
    color_q = find(u, q);
    if (color_p == color_q) return 0;
    for (int i = 0; i < u->n; i++) {
        if (find(u, i) != color_p) continue;
        u->color[i] = color_q;
    }
    return 1;
}

void output(UnionSet *u){
    for (int i = 0; i < u->n; i++) {
        (i % 5 == 0) && printf("\n");
        printf("(%d : %d)", i, u->color[i]);
    }
    return ;
}

int  main(){
    int n;
    scanf("%d", &n);
    UnionSet *u = init(n);
    int a, b;
    while (scanf)

    return 0;
}
