#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define DEBUG
#ifdef DEBUG
#define log(fmt, args...) { \
    printf("[%s] ~ [%s: %d] - (%s) -  ", __FILE__, __func__, __LINE__, #args); \
    printf(fmt, ##args); \
    printf("  "); \
}
#endif
typedef struct Vector {
    int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int*)malloc(sizeof(int) * size);
}

void expand(Vector *vector, int loc, int value) {
    int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for(int i = 0; i < vector->length; ++i) {
        vector->data[i] = old_data[i]; 
    }
    free (old_data);
    log("%d %d", loc, value); 
    printf("expand\n");
}

int insert(Vector *vector, int loc , int value) {
    if(loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if(vector->length >= vector->size) {
        expand(vector, loc, value);
    }
    for(int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }   
    vector->data[loc] = value;
    vector->length++;
    return 1;
}


int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) {
        return ERROR;
    }
    for (int i = index + 1; i < vector->length; ++i) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
    for(int i = 0; i < vector->length; i++) {
        if(i > 0) {
            printf(" ");
        }
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
    int n, loc, value, count;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d", &loc, &value);
        count = insert(a, loc, value);
        if(count != 1) {
            log("%d %d", loc, value); 
            printf("failed\n"); 

        }
        if(count == 1) {
            log("%d %d", loc, value);
            printf("success\n");
        }        
    }
    clear(a);
    return 0;
}

