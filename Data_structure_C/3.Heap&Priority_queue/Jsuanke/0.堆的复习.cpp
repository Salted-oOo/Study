#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current] > h->data[father]) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    } 
    h->size++;
}

void output(Heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

int top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && h->data[lchild] > h->data[max_value]) {
        max_value = lchild;
    }
    if (rchild < n && h->data[rchild] > h->data[max_value]) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[max_value], &h->data[pos]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

void heap_sort(Heap *h) {
    for (int i = h->size - 1; i >= 1; i--) {
        swap(&h->data[0], &h->data[i]);
        update(h, 0, i);
    }
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int n, m, delete_node;
    scanf("%d", &n);
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h, n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        push(h, m);
    }
    scanf("%d", &delete_node);
    while (delete_node--) {
        printf("%d\n", top(h));
        pop(h);
    }
    output(h);
    heap_sort(h);
    output(h);
    clear(h);
    return 0;
}