#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T))
#define init_stack(s, n, T) (__init_stack(s, n, sizeof(T)))
#define push_stack(s, value) ({ \
    __typeof(value) __temp = (value); \
    __push_stack(s, (const char *)(&(__temp))); \
})
#define empty_stack(s) (__empty_stack(s))
#define pop_stack(s) (__pop_stack(s))
#define top_stack(s, T) (*((T *)__top_stack(s)))
#define clear_stack(s) (__clear_stack(s))
#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = (__temp); \
}
 
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

typedef struct Node {
	int flag;
	struct Node *next[26];
} Node;

Node *get_new_node() {
	Node *p = CC(Node, 1);
	p->flag = 0;
}

int insert(Node *tree, char *str) {
	Node *p = tree;
	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			p->next[str[0] - 'a'] = get_new_node();
		}
		p = p->next[str[0] - 'a'];
		//printf("%s\n", p->next[str[0]]);
		str++;
	}
	p->flag = 1;
	return 1;
}

void clear(Node *tree) {
	if (tree == NULL) return ;
	for (int i = 0; i < 26; i++) {
		clear(tree->next[i]);
	}
	free(tree);
	return ;
}

void __output(Node *tree, int ind, char *str) {
	str[ind] = '\0';
	if (tree->flag == 1) {
		printf("%s\n", str);
	}


	for (int i = 0; i < 26; i++) {
		if (tree->next[i] != NULL) 
		str[ind] = i + 'a'; 

		__output(tree->next[i], ind + 1, str);
	}

	return ;
}

typedef struct OutPutArgs {
	Node *tree;
	char *str;
	int ind;
	int status;
	int count;
} OutPutArgs;

void output(Node *tree, int ind, char *str) {
	Stack *s = MC(Stack ,1);
	init_stack(s, 1000, OutPutArgs);
	OutPutArgs opa = {tree, str, ind, 0, 0}, topa;
	push_stack(s, opa);
	while (!empty_stack(s)) {
		OutPutArgs *topa = &top_stack(s, OutPutArgs);
		switch (topa->status) {
			case 0 :
				topa->str[topa->ind] = '\0';
				if (topa->tree->flag == 1) {
					printf("%s\n", topa->str);
				}
				topa->status = 1;
				break;
			case 1 :
				if (topa->count < 26) {
					if (topa->tree->next[topa->count] != NULL) {
						topa->str[topa->ind] = topa->count + 'a';	
					} 
					topa->status = 2;
				} else {
					topa->status = 3;
				}
				break;
			case 2 : {
				OutPutArgs temp = {topa->tree->next[topa->count], topa->str, topa->ind + 1, 1, topa->count};
				push_stack(s, temp);
				(topa->count)++;
				topa->status = 1;
				break;
			}
			case 3 :
				pop_stack(s);
				break;
			default :
				printf("ERROR\n");
				break;
		}
	}
	return ;
}



int main() {
	Node *tree = get_new_node();
	int n;
	char str[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		insert(tree, str);
	}
	output(tree, 0, str);
	clear(tree);
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