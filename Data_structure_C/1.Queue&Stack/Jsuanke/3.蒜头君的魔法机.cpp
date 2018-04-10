#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
	int *element;
	int top, size;
} Stack;

void init(Stack *s, int size) {
	s->element = (int *)malloc(sizeof(int) * size);
	s->size = size;
	s->top = -1;
}

int push(Stack *s, int element) {
	if (s->top >= s->size - 1) {
		return ERROR;
	} 
	s->top++;
	s->element[s->top] = element;
	return OK;
}

int pop(Stack *s) {
	if(s->top < 0) {
		return ERROR;
	}
	s->top--;
	return OK;
}

int empty(Stack *s) {
	if (s->top < 0) {
		return 1;
	} else {
		return 0;
	}
}

int top(Stack *s) {
	return s->element[s->top];
}

void clear(Stack *s) {
	free(s->element);
	free(s);
}

int main() {
	int n, element;
	int flag = 1, count = 0;
	scanf("%d", &n);
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init(stack, n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &element);
		while (count < element) {
			++count;
			push(stack, count);
		}	
        if (empty(stack) || top(stack) != element) {
            flag = 0;
        }
        pop(stack);
    }
    printf("%s\n", flag ? "YES" : "NO");	
    clear(stack);	
	return 0;
}
