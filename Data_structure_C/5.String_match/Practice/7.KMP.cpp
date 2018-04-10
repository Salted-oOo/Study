 #include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void BF(const char *s, const                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  char *t) {
	int i = 0, j;
	int times = 0;
	while (s[i]) {
		j = 0;
		while (t[j] && s[i + j] && t[j] == s[i + j]) {
			times++;
			j++;
		}
		if (t[j] == '\0') {
			printf("BF YES : %d\n", times);
			return ;
		}
		times++;
		i++;
	}
	printf("BF NO : %d\n", times);
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

void kmp_match(char *s, char *t, int *next) {
	int i = 0, j = -1;  //i是大哥,j是小弟
	int times = 0;
	while (s[i]) {
		while (j != -1 && t[j + 1] != s[i]) {
			times++;
			j = next[j];
		}
		if (t[j + 1] == s[i]) {
			times++;
			j++;
		} 
		if (t[j + 1] == '\0') {
			printf("KMP YES : %d\n", times);
			return ;
		}
		times++;
		i++;
	}
	printf("KMP NO : %d\n", times);
	return ;
}

void sunday(char *s, char *t) {
	int str_index[256] = {0};
	int len = strlen(t);
	int s_len = strlen(s);
	for (int i = 0; i < 256; i++) {
		str_index[i] = len + 1;
	}
	for (int i = 0; t[i]; i++) {
		str_index[t[i]] = len - i;
 	}
 	int i = 0, j = 0;
 	int times = 0;
 	while (i + len <= s_len) {
 		if (s[i + j] != t[j]) {
 			times += 2;
 			i += str_index[s[i + len]];
 			j = 0;
 		} else {
 			times += 1;
 			j++;
 		}
 		if (t[j] == '\0') {
 			printf("Sunday YES : %d\n", times);
 			return ;
 		}
 	}
 	printf("Sunday NO : %d\n", times);
 	return ;
}

void shift_and(char *s, char *t) {
	int str_encoed[256] = {0};
	int p = 0, len = 0, times = 0;
	for (int i = 0; t[i]; i++) {
		str_encoed[t[i]] |= (1 << i);
		len++;
		times++;
	}
	for (int i = 0; s[i]; i++) {
		p = (p << 1 | 1) & str_encoed[s[i]];
		times++;
		if (p & (1 << (len - 1))) {
			printf("SHIFT AND YES : %d\n", times);
			return ;
		}
	}
	printf("SHIFT AND YES : %d\n", times);
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
	kmp_match(s, t, next);
	BF(s, t);
	sunday(s, t);
	shift_and(s, t);
//	BF("aecaeaecaed", "aecaed");
	return 0;
}