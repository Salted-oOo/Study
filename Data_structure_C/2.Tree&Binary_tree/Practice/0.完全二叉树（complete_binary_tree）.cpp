#include <stdio.h>
#include <stdlib.h>
void preorder(char *tree, int index, int n) {
	if (index > n) return ;
	printf("%c ", tree[index]);
	preorder(tree, index * 2, n);
	preorder(tree, index * 2 + 1, n);
}

void inorder(char *tree, int index, int n) {
	if (index > n) return ;
	inorder(tree, index * 2, n);
	printf("%c ", tree[index]);
	inorder(tree, index * 2 + 1, n);
}

void postorder(char *tree, int index, int n) {
	if (index > n) return ;
	postorder(tree, index * 2, n);
	postorder(tree, index * 2 + 1, n);
	printf("%c ", tree[index]);
}

int main() {
	int n;
	char *tree;
	while (scanf("%d", &n) != EOF) {
		tree = (char *)malloc(sizeof(char) * (n + 1));
		for (int i = 1; i <= n; i++) {
			tree[i] = i + 'A' - 1;
		}
		preorder(tree, 1, n);
		printf("\n");
		inorder(tree, 1, n);
		printf("\n");
		postorder(tree, 1, n);
		printf("\n");
		free(tree);
	}
	return 0;
}


