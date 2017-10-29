d#include <stdio.h>
#include <stdlib.h>
#include "/home/alivedreams/Study/Test_file/test.h"

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node, *Tree;

void preorder(Tree bt) {
	if (bt == NULL) return ;
	printf("%d ", bt->data);
	preorder(bt->lchild);
	preorder(bt->rchild);
}

void inorder(Tree bt) {
	if (bt == NULL) return ;
	inorder(bt->lchild);
	printf("%d ", bt->data);
	inorder(bt->rchild);
}

void postorder(Tree bt) {
	if (bt == NULL) return ;
	postorder(bt->lchild);
	postorder(bt->rchild);
	printf("%d ", bt->data);
}

Node *init(int data) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

Node *insert(Tree bt, int data) {
	if (bt == NULL) {
		bt = init(data);
	}
	if (bt->data > data) {
		bt->lchild = insert(bt->lchild, data);
	} else if (bt->data < data) {
		bt->rchild = insert(bt->rchild, data);
	}
	return bt;
}

Node *search(Tree bt, int data) {
	if (bt == NULL || bt->data == data) {
		return bt;
	}
	if (bt->data > data) {
		return search(bt->lchild, data);
	} else {
		return search(bt->rchild, data);
	}
}

void clear(Tree bt) {
	if (bt == NULL) return;
	clear(bt->lchild);
	clear(bt->rchild);
	free(bt);
	return ;
}

int main() {
	Tree tree = NULL;
	int opr, n;
	while (scanf("%d", &opr) != EOF) {
		switch (opr) {
			case 0 :
				scanf("%d", &n);
				tree = insert(tree, n);
				break;
			case 1 :
				scanf("%d", &n);
				printf("search result : %p\n", search(tree, n));
				break;
			case 2 :
				printf("preorder");
				preorder(tree);
				printf("\n");
				break;
			case 3 :
			    printf("inorder");
				inorder(tree);
				printf("\n");
				break;
			case 4 :
				printf("postorder");
				postorder(tree);
				printf("\n");
				break;
		}
	}
	return 0;
}



