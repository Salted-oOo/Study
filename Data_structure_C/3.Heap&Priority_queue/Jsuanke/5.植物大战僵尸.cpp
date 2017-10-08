#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define swap(a, b) { \
__typeof(a) __temp; \
__temp = (a); \
(a) = (b); \
(b) = __temp; \
}
 
typedef struct Node {
    int ind, f;
} Node;
 
typedef struct Heap {
    Node *data;
    int size, length;
} Heap;
 
int cmp(Node a, Node b) { 
    if (a.f > b.f) return 1;
    if (a.f == b.f && a.ind < b.ind) return 1;
    return 0;
}
 
void init(Heap *h, int n) {
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->length = n;
    h->size = 0;
}
 
void push(Heap *h, Node value) {
    h->data[h->size] = value;
    int ind = h->size;
    int f = (ind - 1) / 2;
    while (cmp(h->data[ind], h->data[f])) {
        swap(h->data[ind], h->data[f]);
        ind = f;
        f = (ind - 1) / 2;
    }
    h->size++;
}
 
void update(Heap *h, int i, int n) {
    int lchild, rchild, max_value;
    lchild = i * 2 + 1;
    rchild = i * 2 + 2;
    max_value = i;
    if (lchild < n && cmp(h->data[lchild], h->data[max_value])) {
        max_value = lchild;
    }
    if (rchild < n && cmp(h->data[rchild], h->data[max_value])) {
        max_value = rchild;
    }
    if (max_value != i) {
        swap(h->data[max_value], h->data[i]);
        update(h, max_value, n);
    }
}
 
Node top(Heap *h) {
    return h->data[0];
}
 
void pop(Heap *h) {
    if (h->size == 0) return ;
    h->size--;
    swap(h->data[0], h->data[h->size]);
    update(h, 0, h->size);
}
 
int empty(Heap *h) {
    return h->size == 0;
}
 
void clear(Heap *h) {
    free(h->data);
    free(h);
}
 
int main() {
    int t, n, tcase = 0;
    scanf("%d", &t);
    Heap *heap[101];
    for (int i = 1; i <= 100; i++) {
        heap[i] = (Heap *)malloc(sizeof(Heap));
        init(heap[i], 50000);
    }
    while (tcase < t) {
        printf("Case #%d:\n", ++tcase);
        scanf("%d", &n);
        Node zombie;
        int s;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &zombie.f, &s);
            zombie.ind = i + 1;
            push(heap[s], zombie);
        }
        for (int i = 0; i < n; i++) {
            int m = -1;
            Node zombie1, zombie2;
            for (int j = 1; j <= 100; j++) {
                if (empty(heap[j])) continue;
                if (m == -1) {
                    m = j;
                    continue;
                }
                zombie1 = top(heap[m]);
                zombie2 = top(heap[j]);
                zombie1.f = zombie1.f + i * m;
                zombie2.f = zombie2.f + i * j;
                if (cmp(zombie2, zombie1)) {
                    m = j;
                }
            }
            printf("%d", top(heap[m]).ind);
            pop(heap[m]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= 100; i++) {
        clear(heap[i]);
    }
    return 0;
}