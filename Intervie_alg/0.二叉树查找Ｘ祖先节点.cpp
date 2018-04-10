#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1
#define OK 0

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
	int sign;
} Node, *Tree_node;

typedef struct Stack {
	Tree_node *data;
	int size, top;
} Stack, *Stack_node;

void init_stack(Stack *s, int size) {
	s->data = (Tree_node *)malloc(sizeof(Tree_node) * size);

	s->size = size;
	s->top = -1;
}

int push_stack(Stack *s, Tree_node val) {
	if (s->top >= s->size - 1) {
		return ERROR;
	}
	(s->top)++;
	s->data[s->top] = val;
	return OK;
}

int empty_stack(Stack *s) {
	return s->top == -1;
}

Tree_node top_stack(Stack *s) {
	return s->data[s->top];
}

int pop_stack(Stack *s) {
	if (empty_stack(s)) {
		return ERROR;
	}
	(s->top)--;
	return OK;
}

void clear_stack(Stack *s) {
	free(s->data);
	free(s);
}


Tree_node init_tree(int data) {
	Tree_node node = (Tree_node)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	node->sign = 0;
	return node;
}

Tree_node build_tree(const char *str, int *node_num) {
	Tree_node p = NULL, last_p = NULL;
	Stack *s = (Stack *)malloc(sizeof(Stack));
	init_stack(s, strlen(str));
	int flag = 0;
	while (str[0]) {
		switch (str[0]) {
			case '(' : flag = 0; push_stack(s, p); p = NULL; break;
			case ')' : last_p = top_stack(s); pop_stack(s); break;
			case ',' : flag = 1; p = NULL; break;
			case ' ' : break;
			default :
				p = init_tree(str[0]);
				if (!empty_stack(s) && flag == 0) {
					top_stack(s)->lchild = p;
				} else if (!empty_stack(s) && flag == 1) {
					top_stack(s)->rchild = p;
				}
				++(*node_num);
				break;
		}
		++str;
	}
	if (p && !last_p) {
		last_p = p;
	}
	clear_stack(s);
	return last_p;
}
Stack_node find_node(Tree_node p, char ch, int size) {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	init_stack(stack, size);
	push_stack(stack, p);      
	while (top_stack(stack)->data != ch) {
		if (p->lchild != NULL && p->lchild->sign == 0) {
			push_stack(stack, p);
			p->sign = 1;
			p = p->lchild;
			printf("-------lchild--------\n");
			printf("%c\n", top_stack(stack)->data);
			continue;
		} if (p->rchild != NULL && p->rchild->sign == 0) {
			push_stack(stack, p);
			p->sign = 1;
			p = p->rchild;
			printf("-------rchild--------\n");
			printf("%c\n", top_stack(stack)->data);
		} if (p->lchild == NULL && p->rchild == NULL) {
			pop_stack(stack);
			p = top_stack(stack);
			printf("--------NULL---------\n");
			printf("%c\n", top_stack(stack)->data);
		}
	} 
	return stack;
}

void output_node(Stack *s) {
	if (empty_stack(s)) {
		printf("Not found\n");
		return ;
	} 
	while (top_stack(s) != NULL) {
		printf("%c ", top_stack(s)->data);
		pop_stack(s);
	}
	return ;
}



void clear_tree(Tree_node node) {
	if (!node) {
		return ;
	} else if (node->lchild != NULL) {
		clear_tree(node->lchild);
	} else if (node->rchild != NULL) {
		clear_tree(node->rchild);
	}
	free(node);
}


void preorder(Tree_node bt) {
	if (bt == NULL) return ;
	preorder(bt->lchild);
	printf("%c ", bt->data);
	preorder(bt->rchild);
}

int main() {
	char str[16] = "A(B(D,E),C(F,))";
	char ch;
	int i = 0;
//	scanf("%s\n", str);
 //   str = "A(B(D,E),C(F,))"
	scanf("%c", &ch);
	int node_num = 0;
	Tree_node p = build_tree(str, &node_num); 
	Stack_node s = find_node(p, ch, strlen(str));
	printf("preorder");
	preorder(p);
	printf("\n");
	output_node(s);
	clear_tree(p);
	clear_stack(s);
	return 0;
}