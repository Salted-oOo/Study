#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node, *Tree_node;

Node* init_tree(char data) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data= data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void output_tree(Tree_node node) {
	if (node == NULL) return ;
	printf("%c", node->data);
	if (node->lchild == NULL && node->rchild == NULL) {
		return ;
	}
	printf("(");
	if (node->lchild) {
		output_tree(node->lchild);
	}
	if (node->rchild) {
		printf(",");
		output_tree(node->rchild);
	}
	printf(")");
	return ;
}




void clear_tree(Tree_node node) {
	if (node == NULL) {
		return ;
	} if (node->lchild) {
		clear_tree(node->lchild);
	} if (node->rchild) {
		clear_tree(node->rchild);
	}
	free(node);
}

int main() {
	char str[4], ch;
	Tree_node index[26] = {0};
	Tree_node root = NULL, p = NULL;
	while (scanf("%s", str)) {
		if (str[0] == str[1] && str[0] == '^') {
			break;
		}
		p = init_tree(str[1]);
		index[str[1] - 'A'] = p;
		if (str[0] == '^') {
			root = p;
		} else {
			if (str[2] == 'L') {
				index[str[0] - 'A']->lchild = p; 
			} else if (str[2] == 'R') {
				index[str[0] - 'A']->rchild = p;
			} else {
				return 1;
			}
		}
	}
	output_tree(root);
	printf("\n");
	clear_tree(root);
	return 0;
}








