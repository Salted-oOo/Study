#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T))


#define ERROR 0
#define OK 1

typedef struct HashTable {
	char **data;
	//Node **data
	int size;
} HashTable;
 
void init(HashTable *h, int n) {
	h->data = (char **)malloc(sizeof(char *) * n);
	memset(h->data, 0, sizeof(char *) * n);
	h->size = n;
}

int hash_code(HashTable *h, const char *value) {
	unsigned int code = 0;
	for (int i =0; value[i]; i++) {
		code = (code << 3) ^ value[i] ^ (code >> 5);
	}
	return (int)code % h->size;
}

int search(HashTable *h, char *value) {
	int index = hash_code(value);
	int times = 0;
	while (h->data[index] != NULL) {
		if (strcmp(h->data[index], value) == 0) {
			return OK;
		}
		times++;
		index += times * times;
		index %= h->size;
	}
	return ERROR;
}


int insert(HashTable *h, char *value) {
	int index = hash_code(value);
	int times = 0;
	while (h->data[index] != NULL) {
		if (strcmp(h->data[index], value) == 0) {
			return ERROR;
		}
		times++;
		index += times * times;
		index %= h->size;
	}
	h->data[index] = strdup[value];
	return OK;
}


void clear(HashTable *h) {
	for (int i = 0; i < h->size; i++) {
		free(h->data);
	}
	free(h->data);
	free(h);
}


int main() {
	HashTable *h = MC(HashTable, 1);
	init(h, 100);
	printf("%d\n", hash_code(h, "ab"));
	printf("%d\n", hash_code(h, "ba"));


	return 0;
}