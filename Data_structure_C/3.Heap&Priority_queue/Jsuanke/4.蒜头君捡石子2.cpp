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
    int pi, di;
} Node;
 
typedef struct Heap {
    Node *data;
    int size, length;
} Heap;
 
int cmp(Node a, Node b) {
    if (a.pi < b.pi) return 1;
    if (a.pi == b.pi && a.di < b.di) return 1;
    return 0;
}
 
void init(Heap *h, int n) {
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->length = n;
    h->size = 0;
}
 
void push(Heap *h, Node value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (cmp(h->data[current], h->data[father])) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
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
    int t, n, pi, di;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        Node node;
        Heap *heap = (Heap *)malloc(sizeof(Heap));
        scanf("%d", &n);
        init(heap, n);
        for (int i = 0; i < n; i++) {       
            scanf("%d%d", &node.pi, &node.di);
            push(heap, node);
        }
        int i = 1;
        while (!empty(heap)) {
            node = top(heap);
            pop(heap);
            ans = node.pi;
            if (i % 2) {
                node.pi += node.di;
                push(heap, node);
            }
            i++;
        }
        printf("%d\n", ans);
        clear(heap);
    }
    return 0;
}