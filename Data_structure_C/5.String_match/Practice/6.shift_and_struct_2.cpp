#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MC(T, n) (T *)malloc(sizeof(T) * (n));
#define CC(T, n) (T *)calloc((n), sizeof(T));
#define RC(bm, T, n) (T *)realloc(data, n, (T));
 
typedef struct Bitmap {
	int *data;
	int size;
} Bitmap;

void init_bitmap(Bitmap *bm, int n = 1) {
	bm->data = MC(int ,n);
	bm->size = n;
}

void expand_bitmap(Bitmap *bm, int size) {
	int *data_temp = CC(int, size);
	memcpy(data_temp, bm->data, sizeof(int) * bm->size);
	free(bm->data);
	bm->data = data_temp;
	bm->size = size;
	return ;
}

int is_one(Bitmap *bm, int n) {
	if (n / 30 + 1 > bm->size) {
		expand_bitmap(bm, n / 30 + 1);
	}
	return bm->data[n / 30] & (1 << (n % 30));
}

int set_one(Bitmap *bm, int n){
	if (n / 30 + 1 > bm->size) {
		expand_bitmap(bm, n / 30 + 1);
	}
	bm->data[n / 30] |= (1 << (n % 30));
	return ;
}

void left_bitmap(Bitmap *bm, int n) {
	is_one(bm , n);
	bm->data[0] <<= 1;
	for (int i = 1; i < bm->size; i++) {
		bm->data[i] <<= 1;
		bm->data[i] |= (bm->data[i - 1] & (1 << ))
	}


}


void clear(Bitmap *bm) {
	free(bm->data);
	free(bm);	
}

void shift_and(char *s, char *t) {
	Bitmap *str_encoed[256];
	int p = 0, len = 0, times = 0;
	for (int i = 0; i < 256; i++) {
		str_encoed[i] =init_bitmap();
	}
	Bitmap *p = init_bitmap();
	int len = 0;
	int times = 0;
	for (int i = 0; t[i]; i++) {
		set_one(str_encoed[t[i]], i);
		len++;
		times++;
	}
	for (int i = 0; s[i]; i++) {
		times++;
		left_bitmap(p, len);
		set_one(p, 0);
		and_bitmap(p, str_encoed[s[i]], len);
		if (is_one(p, len - 1)){
            printf("SHIFT AND YES : %d\n", times);
            return ;
		}
	}
    printf("SHIFT AND NO : %d\n", times);
    return ;  
}

int main() {
	int next[100];
//	char s[] = "aecaeaecaed";
	char s[] = "aecaea aecaed";
	char t[] = "aecaed";
	get_next(t, next);
	printf("{");
	for (int i = 0; t[i]; i++) {
		printf("%d ", next[i]);
	}
	printf("}\n");
//	kmp_match(s, t, next);
//	BF(s, t);
//	sunday(s, t);
	shift_and(s, t);
//	BF("aecaeaecaed", "aecaed");
	return 0;
}