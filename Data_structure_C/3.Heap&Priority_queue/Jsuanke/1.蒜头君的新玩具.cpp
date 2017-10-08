#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Heap {
	double *data;
	int size, length;
} Heap;

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp; 
}

void init(Heap *heap, int n) {
	heap->data = (double *)malloc(sizeof(double) * n);
	heap->length = n;
	heap->size = 0;
}

void push(Heap *heap, double value) {
	heap->data[heap->size] = value;
	int current = heap->size;
	int father = (current - 1) / 2;
	while (heap->data[current] > heap->data[father]) {
		swap(&heap->data[current], &heap->data[father]);
		current = father;
		father = (current - 1) / 2;
	}
	heap->size++;
}

double top(Heap *heap) {
	return heap->data[0];
}

void update(Heap *heap, int pos, int n) {
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	int max_value = pos;
	if (left < n && heap->data[left] > heap->data[max_value]) {
		max_value = left;
	}
	if (right < n && heap->data[right] > heap->data[max_value]) {
		max_value = right;
	}
	if (max_value != pos) {
		swap(&heap->data[max_value], &heap->data[pos]);
		update(heap, max_value, n);
	}
}

void pop(Heap *heap) {
	swap(&heap->data[0], &heap->data[heap->size - 1]);
	heap->size--;
	update(heap, 0, heap->size);
}

void output(Heap *heap) {
	for (int i = 0; i < heap->size; ++i) {
		printf("%lf ", heap->data[i]); 	
	}
	printf("\n");
}

void heap_sort(Heap *heap) {
	for (int i = heap->size - 1; i >= 1; --i) {
		swap(&heap->data[0], &heap->data[i]);
		update(heap, 0, i);
	}
}
 
void clear(Heap *heap) {
	free(heap->data);
	free(heap);
}

int main() {
	int n, m;
	double ans_r, ans_l;
	double ans;
	scanf("%d", &n);
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	init(heap, n);
	for (int i = 0; i < n; ++i) {
		scanf("%d" ,&m);
		push(heap, m);
	}
	//output(heap);
	for (int i = 1; i < n; i++) {
		ans_l = top(heap);
		pop(heap);
		ans_r = top(heap);
		pop(heap);
 		ans = pow(ans_l, 1.0 / 3.0) * pow(ans_r, 2.0 / 3.0);  
		push(heap, ans);
	}
	printf("%lf\n", top(heap));
	clear(heap);
	return 0;
}