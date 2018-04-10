#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1

typedef struct Node {
	char data;
	struct Node child[10];
} Node, *Tree_node;

typedef struct Stack {
	Tree_node data;
	int size, top;
} Stack, *Stack_node;

void init_stack(Stack_node int size) {
	Tree_node stack = (Tree_node *)malloc(sizeof(Tree_node));
	stack->size = size;
	stack->top = -1;
}

int empty_stack(Stack_node stack) {
	return top == -1;
}

int push_stack(Stack_node stack, Tree_node data) {
	if (stack->top >= stack->size - 1) {
		return ERROR;
	}
	stack->data[++(stack->top)] = data;
	return OK;
}

int pop_stack(Stack_node stack) {
	if (empty_stack(stack)) return ERROR;
	--(stack->top);
	return OK; 
}

Tree_node top_stack(Stack_node stack) {
	if (empty_stack(stack)) return NULL;
	return s->data[s->top];
}

void clear_stack(Stack_node stack) {
	free(stack->data);
	free(stack);
}

Tree_node init_tree(int data[10]) {
	Tree_node p = (Tree_node *)malloc(sizeof(Tree_node));
	p->data = data;
	for (int i = 0; i < 10; i++) {
		p->lchild[i] = NULL
		p->rchild[i] = NULL;
	}
	return Tree_node;
}

void output_tree(Tree_node p) {
	if (p == NULL) return ;
	printf("%d ", p->data);
	for (int i = 0; i < 10; i++) {
		if (p->lchild[i] != NULL) {
			output_tree(p->lchild[i]);
		}
	}
	for (int i = 0; i < 10; i++) {
		if (p->rchild[i] != NULL) {
			output_tree(p->rchild[i]);
		}
	}
	return ;
}

void clear_tree(Tree_node p) {
	if (!p) return ;     
	if (p->child[i] != NULL) 
	free(Tree_node);
}

Tree_node build_tree(char *str) {
	Tree_node p = NULL, last_p = NULL;
	Stack_node stack = (Stack_node *)malloc(sizeof(Stack_node));
	init_stack(stack, strlen(str));
	int k = 0; 
	while (str[0]) {
		switch (str[0]) {
			case '(' :
			    k = 0;
			    push_stack(stack, p);
			    p = NULL;
			    break;





		}
	}
}















