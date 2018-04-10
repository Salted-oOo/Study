#include <stdio.h>
#include <stdlib.h>
 
#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define CC(T, n) (T *)calloc(n, sizeof(T));
 
typedef struct Node {
    int flag;
    struct Node *next[26];
    struct Node *fail;
    struct Node *father;
    int index;
} Node;
 
typedef struct DANode {
    int base, check, fail;
} DANode;
 
Node *get_new_node() {
    Node *p = CC(Node , 1);
    return p;
}
 
int insert(Node *tree, char *str) {
    Node *p = tree;
    int cnt = 0;
    while (str[0]) {
        if (p->next[str[0] - 'a'] == NULL) {
            cnt++;
            p->next[str[0] - 'a'] = get_new_node();
            p->next[str[0] - 'a']->father = p;
            p->next[str[0] - 'a']->index = str[0] - 'a';
        }
        p = p->next[str[0] - 'a'];
        str++;
    }
    p->flag = 1;
    return cnt;
}
 
void output(Node *tree, int ind, char *str) {
    str[ind] = '\0';
    if (tree->flag) {
        printf("%s\n", str);
    }

    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        str[ind] = 'a' + i;
        output(tree->next[i], ind + 1, str);
    }
    return ;
}
 
void clear(Node *tree) {
    if (tree == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(tree->next[i]);
    }
    free(tree);
    return ;   
}
 
int get_base_value(Node *tree, DANode *da_tree) {
    int base = 1;
    int flag = 1;
    while (flag) {
        flag = 0;
        base++;
        for (int i = 0; i < 26; i++) {
            if (tree->next[i] == NULL) continue;
            if (da_tree[base + i].check == 0) continue;
            flag = 1;
            break;
        }
    }
    return base;
}
 
int trie_transfer_da(Node *tree, int index, DANode *da_tree) {
    int base = da_tree[index].base;
    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        da_tree[base + i].check = tree->next[i]->flag ? -index : index;
    }
    int temp, max_index = index;
    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        da_tree[base + i].base = get_base_value(tree->next[i], da_tree);
        temp = trie_transfer_da(tree->next[i], base + i, da_tree);
        if (temp > max_index) max_index = temp;
    }
    return max_index;
}
 
Node *__get_automaton_fail(Node *father, int index, Node *root) {
    if (father == root) return root;
    if (father->fail == NULL) {
        father->fail = __get_automaton_fail(father->father, father->index, root);
    }
    if (father->fail->next[index] != NULL) {

        return father->fail->next[index];
    }
    return __get_automaton_fail(father->fail, index, root);
}
 
void __build_automaton(Node *node, Node *root) {
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        node->next[i]->fail = __get_automaton_fail(node, i, root);
        __build_automaton(node->next[i], root);
    }
    return ;
}
 
void build_automaton(Node *tree) {
    __build_automaton(tree, tree);
}
 
int __get_automaton_fail_da(int father, int index, int root, DANode *da_tree) {
    if (father == root) return root;
    if (da_tree[father].fail == 0) {
        da_tree[father].fail =
            __get_automaton_fail_da(
                abs(da_tree[father].check),
                father - da_tree[abs(da_tree[father].check)].base,
                root,
                da_tree
            );
    }
    if (abs(da_tree[da_tree[da_tree[father].fail].base + index].check) == da_tree[father].fail) {
        return da_tree[da_tree[father].fail].base + index;
    }
    return __get_automaton_fail_da(da_tree[father].fail, index, root, da_tree);
}
 
void __build_automaton_da(int node, int root, DANode *da_tree) {
    for (int i = 0; i < 26; i++) {
        if (abs(da_tree[da_tree[node].base + i].check) != node) continue;
        da_tree[da_tree[node].base + i].fail = __get_automaton_fail_da(node, i, 1, da_tree);
        __build_automaton_da(da_tree[node].base + i, 1, da_tree);
    }
    return ;
}
 
void build_automaton_da(DANode *da_tree) {
    __build_automaton_da(1, 1, da_tree);
}
void output(Node *tree) {
    if (tree == NULL) return ;
    printf("Tree %p, %p: ", tree, tree->fail);
    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        printf("(%c)%p ", i + 'a', tree->next[i]);
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        output(tree->next[i]);
    }
    return ;
}
 
void output_da(DANode *da_tree, int max_index) {
    for (int i = 1; i <= max_index; i++) {
        printf("(%3d|%3d%4d%3d) ", i, da_tree[i].base, da_tree[i].check, da_tree[i].fail);
        if (i % 4 == 0) {
            printf("\n");
        }
    }
    return ;
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
    build_automaton(tree);
    build_automaton_da(da_tree);
    output(tree);
    output_da(da_tree, max_index);
    clear(tree);
    return 0;
}