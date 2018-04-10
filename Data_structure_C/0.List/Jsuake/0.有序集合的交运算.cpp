#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0;
#define OK 1;

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
	vector->length = 0;
	vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    vector->size *= 2;
    vector->data = (int *)realloc(vector->data, vector->size * sizeof(int));
    return ;
}
int insert(Vector *vector, int loc, int index) {
	if (index < 0 || index > vector->length) {
		return ERROR;
	}
	if (vector->length == vector->size) {
		expand(vector);
	}
	for (int i = vector->length; i > index; --i) {
		vector->data[i] = vector->data[i - 1];
	}
	vector->data[index] = loc;
	vector->length++;
	return OK;
}

/*int delete_node(Vector *vector, int index) {
	int delete_node_value = vector->data[index];
	if (index < 0 || index > vector->length) {
		return ERROR;
	}
	for (int i = index + 1; i < vector->length; ++i) {
		vector->data[i - 1] = vector->data[i];
	}
	vector->length--;
	return delete_node_value;
}
*/

void output(Vector *vector) {
	printf("%d\n", vector->length);
	for (int i = 0; i < vector->length; ++i) {
		if (i == 0) {
			printf("%d", vector->data[i]);
		}
		else {
			printf(" %d", vector->data[i]);
		}
	}
	printf("\n");
	return;
}

void merge(Vector *a, Vector *b, Vector *c) {
	int x, y, z;
	x = y = z = 0;
	while(x < a->length && y < b->length) {
		if (a->data[x] < b->data[y]) {
			++x;
		}else if (a->data[x] > b->data[y]) {
			++y;
		}else {
			insert(c, a->data[x], z++);
			++x, ++y;
		}
	}
}


void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}
 

int main() {
	Vector *a = (Vector *)malloc(sizeof(Vector));
	Vector *b = (Vector *)malloc(sizeof(Vector));
	Vector *c = (Vector *)malloc(sizeof(Vector));
	int n, m, p, q;
	scanf("%d", &n);
	init(a, n);
	for (int i = 0; i < n; ++i) {
        scanf("%d", &p);
		insert(a, p, i);
	}
	scanf("%d", &m);
	init(b, m);	
	for (int j = 0; j < m; ++j) {
		scanf("%d", &q);
		insert(b, q, j);
	}
    init(c, a->size + b->size);
    merge(a, b, c);
    output(c);
    clear(a);
    clear(b);
    clear(c);
    return 0;
}
