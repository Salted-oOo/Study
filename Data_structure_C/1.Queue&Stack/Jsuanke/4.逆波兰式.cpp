#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int *elements;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
    s->elements = (int *)malloc(sizeof(int) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, int element) {
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

int precede(int operators1, int operators2) {
    int count1, count2;
    if (operators1 == '+' || operators1 == '-') {
        count1 = 1;
    } else {
        count1 = 2;
    }
    if (operators2 == '+' || operators2 == '-') {
        count2 = 1;
    } else {
        count2 = 2;
    }
    return count1 > count2; 
}
int operate(int operators, int a, int b) {
    if (operators == '+') return a + b;
    else if (operators == '-') return b - a;
    else if (operators == '*') return a * b;
    else if (operators == '/') return b / a;
    else return 0;
}
void calc(Stack *numbers, Stack *operators) {
    int a, b;
    a = top(numbers);
    pop(numbers);
    b = top(numbers);
    pop(numbers);
    push(numbers, operate(top(operators), a, b));
    pop(operators);
}

void clear(Stack *s) {
    free(s->elements);
    free(s);
}

int main() {
    int n;
    char str[25];
    scanf("%s", str);
    n = strlen(str);
    Stack *numbers = (Stack *)malloc(sizeof(Stack));
    init(numbers ,n);
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(operators, n);
    char *buffer = (char *)malloc(sizeof(char) * (n + 1));
    //scanf("%s", buffer);
    strcpy(buffer, str);
    int i = 0;
    while (i < n) {
        if (isdigit(buffer[i])) {
            push(numbers, buffer[i] - '0');  
            i++;
        } else {
            if (empty(operators) || precede(buffer[i], top(operators)) ) {
                push(operators, buffer[i]);
                i++;
            } else {
                calc (numbers, operators);
            }
        }
    }
    while (!empty(operators)) {
        calc(numbers, operators);
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(operators);
    free(buffer);
    return 0;
}