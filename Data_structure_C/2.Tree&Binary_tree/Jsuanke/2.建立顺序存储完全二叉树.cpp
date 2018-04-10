#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node, *tree;

Node* init(char data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void output(tree p) {
    if (!p) return ;
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
}

void clear(tree p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
} 

int main() {
	char str[10000];
	char ch;
	int i = 0; 
	    while (scanf("%c", &ch)) {
        if (ch == '$')  break;
        if (ch == ' ')  continue;
        str[i++] = ch;
    }
	int len = strlen(str); 
	tree *p_node = (tree *)malloc(sizeof(tree) * (len + 1));
	int flag = 1;
	p_node[flag] = NULL; 
	for (int i = 0; i < len; ++i) {
		p_node[flag] = init(str[i]);
		if (flag != 1) {
			if (flag % 2) {
				p_node[flag / 2]->rchild = p_node[flag];
			} else {
				p_node[flag / 2]->lchild = p_node[flag];
			}
		}
		++flag;
	}
	output(p_node[1]);
	printf("\n");
	clear(p_node[1]);
	free(p_node);
	return 0;
}