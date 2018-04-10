#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet{
    int *father;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
    p->father = (int *)malloc(sizeof(int) * n);
    p->n = n;
    for (int i = 0; i < p->n; i++) {
        p->father[i] = i;
    }
    return p;
}

void clear(UnionSet *u){
    free(u->father);
    free(u);
}

int find(UnionSet *u, int ind) {
    if(u->father[ind] == ind) {
        return ind;
    }
    return find(u, u->father[ind]);
}

int merge(UnionSet *u, int p, int q) {
    int father_p = find(u, p);
    int father_q = find(u, q);
    if (father_p == father_q) return 0;
    u->father[father_p] = father_q;
    return 1;
}
void output(UnionSet *u){
    for (int i = 0; i < u->n; i++) {
        (i % 5 == 0) && printf("\n");
        printf("(%d : %d)", i, u->father[i]);
    }
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    UnionSet *u = init(n);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d -> %d : %d\n", a, b, merge(u, a, b));
    }
    output(u);
    clear(u);
    return 0;
}
