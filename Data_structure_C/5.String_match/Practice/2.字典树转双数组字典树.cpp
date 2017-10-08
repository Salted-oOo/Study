#include <stdio.h>
#include <stdlib.h>

#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T))

typedef struct Node {
	int flag;
	struct Node *next[26];
} Node;

typedef struct DANode {
	int base, check;
} DANode;

Node *get_new_node() {
	Node *p = CC(Node, 1);
	p->flag = 0;
}

int insert(Node *tree, char *str) {
	Node *p = tree;
	int cnt = 0;
	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			cnt++;
			p->next[str[0] - 'a'] = get_new_node();
		}
		p = p->next[str[0] - 'a'];
		str++;
	}
	p->flag = 1;
	return cnt;
}

void clear(Node *tree) {
	if (tree == NULL) return ;
	for (int i = 0; i < 26; i++) {
		clear(tree->next[i]);
	}
	free(tree);
	return ;
}

void sort(Node *tree, int ind, char *str) {
	str[ind]  = '\0';
	if (tree->flag == 1) {
		printf("%s\n", str);
	}
	for (int i = 0; i < 26; ++i) {
		if (tree->next[i] == NULL) continue ;
		str[i] = i + 'a'; 
		sort(tree->next[i], ind + 1, str);

	}
	return ;
}

int get_base_value(Node *tree, DANode *da_tree) {
	int base = 1;
	int flag = 1;
	while (1) {
		flag = 0;
		base++;
		for (int i = 0; i < 26; i++) {
			if (tree->next[i] == NULL) continue;
			flag += da_tree[base + i].check;
		}
	}
	return base;
}

int trie_transfer_da(Node *tree, int index, DANode *da_tree) {
	int base = da_tree[index].base;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] == NULL) continue;
		da_tree[base + i].check = tree->next[i]->flag ? index;
	}
	int temp, max_index = index; 
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] == NULL) continue;
		da_tree[base + i].base = get_base_value(tree->next[i], da_tree);
		trie_transfer_da(tree->next[i], base + i, da_tree);
		if (temp > max_index) max_index = temp;
	}
	return max_index;
}


int main() {
	Node *tree = get_new_node();
	int n, node_cnt = 1;
	char str[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		node_cnt += insert(tree, str);
	}
	DANode *da_tree = CC(DANode, node_cnt * 26);
	da_tree[1].base = 2;
	int max_index = trie_transfer_da(tree, 1, da_tree);
	printf("trie : %lu Byte\n", node_cnt * sizeof(Node));
	printf("double array trie %lu Byte\n", max_index * sizeof(DANode));
	for (int i = 1; i <= max_index; i++) {
		printf("(%d %d %d)",i, da_tree[i].base, da_tree[i].check);
		if (i % 10 == 0) {
			printf("%s\n", );
		}
	}
	sort(tree, 0, str);
	clear(tree);
	return 0;
}