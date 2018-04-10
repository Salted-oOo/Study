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

int insert(Vector *vector, int loc, int index) {
	if (index < 0 || index > vector->length) {
		return ERROR;
	}
	for (int i = vector->length; i > index; --i) {
		vector->data[i] = vector->data[i - 1];
	}
	vector->data[index] = loc;
	vector->length++;
	return OK;
}

int delete_node(Vector *vector, int index) {
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

void output(Vector *vector) {
	for (int i = 0; i < vector->length; ++i) {
		if (i == 0) {
			printf("%d", vector->data[i]);
		}
		else {
			printf(" %d", vector->data[i]);
		}
	}
	printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}
 

int main() {
	Vector *a = (Vector *)malloc(sizeof(Vector));
    int n, m, t, count, i = 0;
    scanf("%d%d", &n, &t);
    init(a, n);
 	count = n;
    while(n--) {
    	scanf("%d", &m);
    	insert(a, m, i);
    	i++;
    }
    while(t--) {
    	int delete_node_value = delete_node(a, 0);
    	insert(a, delete_node_value, count - 1);
    }
    output(a);
    clear(a);
    return 0;
}