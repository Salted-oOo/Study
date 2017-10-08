#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ERROR 0;
#define OK 1;
typedef struct {
	int c, e;
} Node;

typedef struct Vector {
	int size, length;
    Node *data;
} Vector;

int init(Vector *vector, int size) {
	vector->size = size;
	vector->data = (Node *)malloc(sizeof(Node) * size);
    if (vector->data == NULL) {
        return ERROR;
    }
	vector->length = 0;    
}

/*void expand(Vector *vector) {
    vector->size *= 2;
    vector->data = realloc(vector->data, vector->size * sizeof(Node));
    return;
}
*/

int insert(Vector *vector, Node loc, int index) {
	if (index < 0 || index > vector->length) {
		return ERROR;
	}
   // if (vector->length == vector->size) {
     //   expand(vector);
   // }	
	for (int i = vector->length; i > index; --i) {
		vector->data[i] = vector->data[i - 1];
	}
	vector->data[index] = loc;
	vector->length++;
	return OK;
}

void output(Vector *vector, int x) {
	int ret = 0;
	for(int i = 0; i < vector->length; ++i) {
		ret += vector->data[i].c * (int)pow(x, vector->data[i].e);
	}
	printf("%d\n", ret);
}

void clear(Vector *vector) {
	free(vector->data);
	free(vector);
}
 

int main() {
	Node node;
	Vector *a = (Vector *)malloc(sizeof(Vector));
    int m, c, e, x;
    scanf("%d", &m);
    init(a, m);
    for (int i = 0; i < m; ++i){
    	scanf("%d%d", &node.c, &node.e);
    	insert(a, node, i);
    }
    scanf("%d", &x);
    output(a, x);
    clear(a);
    return 0;
}