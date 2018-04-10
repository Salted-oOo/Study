#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    char *elements;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
    s->elements = (char *)malloc(sizeof(char) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, char element) {
    if (s->top_index >= s->max_size - 1) {
        return ERROR;
    }
    s->top_index++;
    s->elements[s->top_index] = element;
    return OK;
}

int pop(Stack *s) {
    if (s->top_index < 0) {
        return ERROR;
    }    
    s->top_index--;
    return OK;
}

int top(Stack *s) {
    return s->elements[s->top_index];
}

int empty(Stack *s) {
    if (s->top_index < 0) {
        return 1;
    } else {
        return 0;
    }
}


void clear(Stack *s) {
    free(s->elements);
    free(s);
}

int main() {
    char str[30];
    int flag = 0;
    Stack *stack1 = (Stack *)malloc(sizeof(Stack));
    Stack *stack2 = (Stack *)malloc(sizeof(Stack));
    init(stack1, 30);
    init(stack2, 30);
    scanf("%s", str);
    int len = strlen(str);
    len = len - 1;
    for (int i = 0; i < len; i++) {
        push (stack1, str[i]);       
    }
    for (int i = len - 1; i >= 0; i--) {
        push (stack2, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if(top(stack1) != top(stack2)) {
            flag = 1;
        }
        pop(stack1);
        pop(stack2);
    }
    printf("%s\n", flag == 1 ? "false" : "true");
    clear(stack1);
    clear(stack2);
    return 0;
}