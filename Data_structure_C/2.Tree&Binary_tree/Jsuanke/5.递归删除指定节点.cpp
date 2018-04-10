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

Tree_node build_tree(char *str) {
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

void outout_tree(Tree_node p, char table_node) {
    if (p == NULL || p->data == table_node) {
        return ;
    }
    printf("%c", p->data);
    if ((p->lchild == NULL || p->lchild->data == table_node) &&
        (p->rchild == NULL || p->rchild->data == table_node)) {
        return ;
    }
    printf("(");
    if (p->lchild && p->lchild->data != table_node) {
        outout_tree(p->lchild, table_node);
    }
    if (p->rchild && p->rchild->data != table_node) {
        printf(",");
        outout_tree(p->rchild, table_node);
    }
    printf(")");
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
    char str[40], table_node;
    int i = 0;
    while(1) {
        scanf("%c", &table_node);
        if (table_node == '\n') {
            break;
        }
        str[i++] = table_node;
    }
    str[i] = 0;
    scanf("%c", &table_node);
    Tree_node p = build_tree(str);
    outout_tree(p, table_node);
    clear_tree(p);
    return 0;
}