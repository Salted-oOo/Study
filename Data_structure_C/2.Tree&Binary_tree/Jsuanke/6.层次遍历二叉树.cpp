#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define ERROR 0
#define OK 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *Tree_node;

typedef struct Stack {
    Tree_node *data;
    int size, top;
} Stack, *Stack_node;

typedef struct Queue {
	Tree_node *data;
	int length, count;
	int head, tail;
} Queue, *Queue_node;

void init_queue(Queue *q, int length) {
	q->data = (Tree_node *)malloc(sizeof(Tree_node) * length);
	q->length = length;
	q->count = 0;
	q->head = 0;
	q->tail = -1;
}

int empty_queue(Queue *q) {
	return q->count == 0;
}

int push_queue(Queue *q, Tree_node value) {
	if (q->count == q->length) {
		return ERROR;
	}
	++(q->tail);
	++(q->count);
	q->tail %= q->length;
	q->data[q->tail] = value;
	return OK;
}

Tree_node front_queue(Queue *q) {
	return q->data[q->head];
}

int pop_queue(Queue *q) {
	if (empty_queue(q))  return ERROR ;
	++(q->head);
	--(q->count);
	q->head %= q->length;
	return OK;
}

void clear_queue(Queue *q) {
	if (!q) return ;
	free(q->data);
	free(q);
}

void init_stack(Stack *stack, int size) {
    stack->data = (Tree_node *)malloc(sizeof(Tree_node) * size);
    stack->size = size;
    stack->top = -1;
}

int push_stack(Stack *stack, Tree_node val) {
    if (stack->top >= stack->size - 1) {
        return ERROR;
    }
    ++(stack->top);
    stack->data[stack->top] = val;
    return OK;
}

int empty_stack(Stack *stack) {
    return stack->top == -1;
}

int pop_stack(Stack *stack) {
    if (empty_stack(stack)) {
        return ERROR;
    }
    --(stack->top);
    return OK;
}

Tree_node top_stack(Stack *stack) {
    if (empty_stack(stack)) {
        return NULL;
    }
    return stack->data[stack->top];
}

void clear_stack(Stack *stack) {
    free(stack->data);
    free(stack);
}

Tree_node init_tree(char data) {
    Tree_node node = (Tree_node)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Tree_node build_tree(char *str, int *node_num) {
    Tree_node p = NULL, last_p = NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init_stack(stack, strlen(str));
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' : flag = 0; push_stack(stack, p); p = NULL; break;
            case ')' : last_p = top_stack(stack); pop_stack(stack); break;
            case ',' : flag = 1; p = NULL; break;
            case ' ' : break;
            default  :
                p = init_tree(str[0]);
                if (!empty_stack(stack) && flag == 0) {
                    top_stack(stack)->lchild = p;
                } else if (!empty_stack(stack) && flag == 1) {
                    top_stack(stack)->rchild = p;
                }
                ++(*node_num);
                break;
        }
        ++str;
    }
    if (p && !last_p) {
        last_p = p;
    }
    clear_stack(stack);
    return last_p;
}

void output(Tree_node p, int node_num) {
	if (node_num == 0) return ;
	printf("%c", p->data);
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	//Stack *stack_out = (Stack *)malloc(sizeof(Stack));
	//init_stack(stack_out, strlen[str]);
	//push_stack(stack_out, p);
	Tree_node temp_p;
	init_queue(queue, node_num);
	push_queue(queue, p);
	while (!empty_queue(queue)) {
		temp_p = front_queue(queue);
		if (temp_p->lchild) {
			printf(" %c", temp_p->lchild->data);
			push_queue(queue, temp_p->lchild);
		}
		if (temp_p->rchild) {
			printf(" %c", temp_p->rchild->data);
			push_queue(queue, temp_p->rchild);
		}
		pop_queue(queue);
	}
	clear_queue(queue);
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

int main() {
    char str[100] = {0}, ch;
    int i = 0;
    scanf("%s", str);
    int node_num = 0;
    Tree_node p = build_tree(str, &node_num);
    output(p, node_num);
    clear_tree(p);
    return 0;
}