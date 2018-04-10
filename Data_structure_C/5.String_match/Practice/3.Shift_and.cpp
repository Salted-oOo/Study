#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
	char *data ;
	int size; 
} Data;

void init(Data *str, int size) {
	str->data = (char *)malloc(sizeof(char) * size);
	memset(str->data, 0, sizeof(char) * size);
	str->size = size;
}

void get_next(char *t, int *next) {
	next[0] = -1;
	int j = 1, match = -1;
	while (t[j]) {
		while (match != -1 && t[match + 1] != t[j]) {
			match = next[match];
		}
		if (t[match + 1] == t[j]) {
			next[j] = match + 1;
			match++;
		} else {
			next[j] = match;
		}
		j++;
	}
	return ;
}

void shift_and(Data *s, Data *t) {
	int str_encoed[256][20] = {0};
	//Data *p = (Data *)malloc(sizeof(Data)); 
	int p[20] = {0}, len = 0, times = 0, l = 0, k = 0, size = 0, size2 = 0;
	for (int i = 0; t->data[i]; i++) {
		while(size % 31 != 0) {
			str_encoed[t->data[i]][l] |= (1 << i);
			str_encoed[t->data[i]][l + 1] = str_encoed[t->data[i]][l] >> 31;
			len++;
			times++;
			size++;
		}
		l++;
		size = 0; 
	}
	for (int i = 0; s->data[i]; i++) {
		while (size2 % 31 != 0) {
			size2++;
			p[k] = (p[k] << 1 | 1) & str_encoed[k][s->data[i]];
			times++;
			if (p[k] & (1 << (len - 1))) {
				printf("SHIFT AND YES : %d\n", times);
				return ;
			}
		}
		printf("SHIFT AND YES : %d\n", times);
		return ;
	}
	k++;
	size2 = 0;
}

int main() {
//	int next[100];
	int n, m;
	scanf("%d%d", &n, &m);
	Data *str_mum = (Data *)malloc(sizeof(Data));
	Data *str_son = (Data *)malloc(sizeof(Data));
	init(str_mum, n);	
	init(str_son, m);
	scanf("%s", str_mum->data);
	scanf("%s", str_son->data);
	shift_and(str_mum, str_son);





//	for (int i = 0; i < n; i++) {
//		printf("%c ", str->data[i]);
//	}

/*	char s[] = "aecaeaaecaed";
	char t[] = "aecaed";
	get_next(t, next);
	printf("{");
	for (int i = 0; t[i]; i++) {
		printf("%d ", next[i]);
	}
	printf("}\n");
	shift_and(s, t);
*/
	return 0;
}