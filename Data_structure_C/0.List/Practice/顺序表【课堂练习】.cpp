#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size;
	int length;
	int *data;
} Vector;

void init(Vector *vec, int n) {
	vec->data = (int *)malloc(n * sizeof(int));
	vec->size = n;
	vec->length = 0;
}

int expanf(Vector *vec) {
	vec->size *= 2;
	int *old_data = vec->data;
	vec->data = (int *)realloc(vec->data, vec->size * sizeof(int));
	if(vec->data == NULL) {
		vec->data = old_data;
		return ERROR;
	}
	return OK;
}

int insert(Vector *vec, int value, int index) {
	if(index < 0 || index > vec->length) {	
		return ERROR;
	}
	if(vec->length >= vec->size) {
		expanf(vec);
		if(!expanf(vec)) {
			return ERROR;
		}
	}
	for(int i = vec->length; i > index; --i) {
		vec->data[i] = vec->data[i - 1]; 
	}
	vec->data[index] = value;
	vec->length++;
	return OK;
}


int delete_node(Vector *vec, int index) {
	if(index < 0 || index > vec->length) {
		return ERROR;
	}
	for(int i = index; i < vec->length - 1; ++i) {
		vec->data[i] = vec->data[i + 1];
	}
	vec->length--;
	return OK;
}

void output(Vector *vec) {
	for(int i = 0; i < vec->length; i++) {
		if(i == 0) {
			printf("%d", vec->data[i]);
		}
		else{
			printf(" %d", vec->data[i]);
		}
	}
	printf("\n");
}


int clear(Vector *vec) {
	if (vec == NULL) {
		return OK;
	}
	free(vec->data);
	free(vec);
}

int main() {
	int n, del, index, value;
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	init(vec, 100);
    while(scanf("%d", &n) != EOF) {
    	if(n == 1) {
    		scanf("%d%d", &value, &index);
    		insert(vec, value, index);
    		output(vec);
    	}
    	if(n == 2) {
    		scanf("%d", &del);
    		delete_node(vec, del);
    		output(vec);
    	}

    }
    free(vec);
	return 0;
}


TEST(vector, insert_tail) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	init(vec, 20);
	for(int i = 0; i < 10; i++) {
        insert(vec, i, i);
	    ASSERT_EQ(i, vec->data[i]);
	}
	free(vec);
}