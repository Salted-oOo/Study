#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MC(T, n) ((T *)malloc(sizeof(T) * n))
#define init_stack(s, n, T) (__init_stack(s, n, sizeof(T)))
#define push_stack(s, value) ({ \
    __typeof(value) __temp = (value); \
    __push_stack(s, (const char *)(&(__temp))); \
})
#define empty_stack(s) (__empty_stack(s))
#define pop_stack(s) (__pop_stack(s))
#define top_stack(s, T) (*((T *)__top_stack(s)))
#define clear_stack(s) (__clear_stack(s))
 
#define ERROR 0
#define OK 1
 

void __init_stack(Stack *s, int n, int value_size);
int __push_stack(Stack *s, const char *value);
int __empty_stack(Stack *s);
int __pop_stack(Stack *s);
char *__top_stack(Stack *s);
void __clear_stack(Stack *s);
Node *init(int val);
Node *build_tree(char *str, int *node_num);

 

typedef struct Stack {
    char *data;
    int top, size;
    int value_size;
} Stack;

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct PreoderArgs {
    Node *root;
    int status;
} PreoderArgs;

int __preorder(Node *root) {
    //if (root == NULL) return 1;
    printf("%d\n", root->val);
    //root->lchild && preorder(root->lchild);
    //root->rchild && preorder(root->rchild);
    return 1;
}

int __postorder(Node *root) {
    //if (root == NULL) return 1;
    //root->lchild && postorder(root->lchild);
    //root->rchild && postorder(root->rchild);
    printf("%d\n", root->val);
    return 1;
}

int postorder(Node *root) {
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, PostorderArgs);

    PostorderArgs pa;
    pa.root = root;
    pa.status = 0;
    push_stack(s, pa);

    while (!empty_stack(s)) {
        PostorderArgs *tpa = top_stack(s, PostorderArgs);
        switch (tpa->status) {
            case 0:
                if (tpa->root == NULL) {
                    tpa->status = 4;
                } else {
                    tpa->status = 1;
                }
                break;
            case 1:
                if (tpa->root->lchild) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 2;
                break;
            case 2:
                if (tpa->root->rchild) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 3;
                break;
            case 3:
                __postorder(tpa->root);
                tpa->status = 4;
            case 4:
                pop_stack(s);
            default :
                printf("ERROR");

        }
    }
    return 1;
}

int preorder(Node *root) {
    Stack *s = MC(Stack ,1);
    init_stack(s, 1000, PreoderArgs);

    PreoderArgs pa;
    pa.root = root;
    pa.status = 0;
    push_stack(s, pa);

    while (!empty_stack(s)) {
        PreoderArgs *tpa = top_stack(s, PreoderArgs);
        switch (tpa->status) {
            case 0:
                if (tpa->root == NULL) {
                    tpa->status = 4;
                } else { 
                    tpa->status = 1;
                }
                break;
            case 1:
                __preorder(tpa->root);
                tpa->status = 2;
                break;
            case 2:
                if (tpa->root->lchild) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 3;
                break;
            case 3:
                if (tpa->root->rchild) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    push_stack(s, pa);
                }
                tpa->status = 4;
                break;               
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
        }
    }
    return 1;
}

 
int main() {
    char s[] = "6(4(7,8),9(1,(,5),2))";
    Node *root = build_tree(s);
    preorder(root);
    return 0;
 /*   Stack *s = MC(Stack, 1);
    init_stack(s, 100, double);
    push_stack(s, 4.8);
    push_stack(s, 8.3);
    push_stack(s, 3.8);
    push_stack(s, 1.2);
    while (!empty_stack(s)) {
        printf("%lf\n", top_stack(s, double));
        pop_stack(s);
    }
    clear_stack(s);
    s = MC(Stack, 1);
    init_stack(s, 100, int);
    push_stack(s, 78);
    push_stack(s, 54);
    push_stack(s, 65);
    push_stack(s, 12);
    while (!empty_stack(s)) {
        printf("%d\n", top_stack(s, int));
        pop_stack(s);
    }
    return 0;
    */
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


Node *init(int val) {
    Node *p = MC(Node, 1);
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *build_tree(char *str, int *node_num) {
    Node *p = NULL, *last_p = NULL;
    Stack *stack = MC(Stack, 1);
    init_stack(stack, strlen(str), Node *);
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(' : flag = 0; push_stack(stack, p); p = NULL; break;
            case ')' : last_p = top_stack(stack, Node *); pop_stack(stack); break;
            case ',' : flag = 1; p = NULL; break;
            case ' ' : break;
            default  :
                p = init_tree(str[0] - '0');
                if (!empty_stack(stack) && flag == 0) {
                    top_stack(stack, Node *)->lchild = p;
                } else if (!empty_stack(stack) && flag == 1) {
                    top_stack(stack, Node *)->rchild = p;
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