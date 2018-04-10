#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int times = 0;

typedef struct Shift {
	int len;
	int **encode;
} Shift;

void init(Shift *s, int size) {
	s->encode = (int **)malloc(sizeof(int *) * 256);
	for (int i = 0; i < 256; i++) {
		s->encode[i] = (int *)calloc(size, sizeof(int));
	}
	s->len = 0;
	return ;
}

void get_bit(Shift *s, char *str_son) {
	for (int i = 0; str_son[i]; i++) {
		s->encode[str_son[i]][i / 32] |= (1 << (i % 32));
		s->len++;
		times++;
    }
    return ;
}

void binary(Shift *s, char *str_mum, int *p) {
	int flag = 0;
	for (int i = 0; str_mum[i]; i++) {
		times++;
		flag = !!(p[0] >> 31);
		p[0] = (p[0] << 1 | 1);
		for (int j = 1; j < s->len; j++) {
			if (flag == 0) {
				flag = !!(p[j] >> 31);
				p[j] = (p[j] << 1);
			} else {
				flag = !!(p[j] >> 31);
				p[j] = (p[j] << 1 | 1);
			}
		}
	}
	return ;
}

void equal(Shift *s, char *str_mum, int *p) {
	for (int i = 0; str_mum[i]; i++) {
		for (int j = 0; j < s->len; j++) {
			p[j] = p[j] & s->encode[str_mum[i]][j];
		}
	}
	return ;
}

void output(Shift *s, char *str_mum, int *p) {
	for (int i = 0; str_mum[i]; i++) {
		int k = s->len / 32;
		int z = s->len % 32;
		if (p[k] & (1 << (z - 1))) {
			printf("SHIFT AND YES :%d\n", times);
			return ;
		}
	}
	printf("SHIFT AND YES : %d\n", times);
	return ;
}

void clear_s(Shift *s) {
	for (int i = 0; i < 256; i++) {
		if (s->encode[i] != NULL) {
			free(s->encode[i]);
		}
	}
	free(s->encode);
	free(s);
}

void clear_p(int *p){
	free(p);
}

int main() {
	char str_mum[] = "aecaea aecaed";
	char str_son[] = "aecaed";
//	scanf("%s", str_mum);
//	scanf("%s", str_son);
	Shift *s = (Shift *)malloc(sizeof(Shift));
	init(s, strlen(str_son));
	int *p = (int *)calloc(strlen(str_son), sizeof(int));
	get_bit(s, str_son);
	binary(s, str_mum, p);
	equal(s, str_mum, p);
	output(s, str_mum, p);
	clear_s(s);
	clear_p(p);
//	printf("%s\n", str_mum);
//	printf("%s\n", str_son);
	return 0;
}