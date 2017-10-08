#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MC(T, n) ((T *)malloc(sizeof(T) * n))
#define init_stack(s, n, T) (__init_stack(s, n, size(T)))
#define push_stack(s, value) ({ \
	__typeof(value) __temp = (value); \
	__push_stack(s, (const char *)(&(value))); \
})
#define empty_stack(s) (__empty_stack(s))
#define pop_stack(s) (__pop_stack(s))
#define top_stack(s, T) (*((T *)__top_stack(s)))
#define clear_stack(s) (__clear_stack(s))
 
#define ERROR 0
#define OK 1


typedef struct Stack {
	char *data;
	int top, size;
	int value_size;
} Stack;


void __init_stack(Stack *s, int n, int value_size);
int __push_stack(Stack *s, const char *value);
int __empty_stack(Stack *s);
int __pop_stack(Stack *s);
char *__top_stack(Stack *s); 
void __clear_stack(Stack *s); 

int main() {
	Stack *s = MC(Stack, 1);
	init_stack(s, 100, double);
	push_stack(s, 3.6);
	push_stack(s, 7.8);
	push_stack(s, 5.6);
	push_stack(s, 4.3);
	while (!empty_stack(s)) {
		printf("%lf\n", top_stack(s, double));
		pop_stack(s);
	}
	clear_stack(s);
	s = MC(Stack, 1);
	init_stack(s, 100, int);
	push_stack(s, 36);
	push_stack(s, 78);
	push_stack(s, 56);
	push_stack(s, 43);
	while (!empty_stack(s)) {
		printf("%d\n", top_stack(s, int));
		pop_stack(s);
	}
	return 0;
}


void __init_stack(Stack *s, int n, int value_size) {
	s->data = (char *)malloc(value_size * n);
	s->top = -1;
	s->size = n;
	s->value_size = value_size;
	return ;
}

int __push_stack(Stack *s, const char *value) {
	if (s->top == s->size - 1) {
		return ERROR;
	}
	++(s->top);
	memcpy(s->data + s->top * s->value_size, value, s->value_size);
	return OK;
}

int __empty_stack(Stack *s) {
	return s->top == -1;
}

int __pop_stack(Stack *s) {
	if (__empty_stack(s)) {
		return ERROR;
	}
	--(s->top);
	return OK;
}

char *__top_stack(Stack *s) {
	if (__empty_stack(s)) {
		return NULL;
	}
	return s->data + s->top * s->value_size;
}

void __clear_stack(Stack *s) {
	free(s->data);
	free(s);
	return ;
} 


