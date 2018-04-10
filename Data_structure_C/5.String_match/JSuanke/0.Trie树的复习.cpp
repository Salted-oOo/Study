/*
* @Author: salted_fish
* @Date:   2017-12-07 12:35:35
* @Last Modified by:   salted_fish
* @Last Modified time: 2017-12-10 14:37:55
*/
/*************************************************************************
    > Author:    hug
    > Problem:   字符串匹配算法-Trie 树的复习
    > Mail:      hug@haizeix.com
************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
const int N = 100010;
const int SIZE = 26;
const char BASE = 'a';
 
typedef struct TrieNode {
    struct TrieNode **next;
} TrieNode, *Trie;
 
TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    memset(p->next, 0, sizeof(TrieNode *) * SIZE);
    return p;
}
 
void clear(Trie tree) {
    if (!tree) return ;
    TrieNode *p = tree;
    for (int i = 0; i < SIZE; i++) {
        clear(p->next[i]);
    }
    free(p->next);
    free(p);
}
 
void insert(Trie tree, char *str) {
    TrieNode *p = tree;
    while (*str) {
        if (p->next[str[0] - BASE] == NULL) {
            p->next[str[0] - BASE] = new_node();
        }
        p = p->next[str[0] - BASE];
        ++str;
    }
}
 
int search(TrieNode *p) {
    if (!p) return 0;
    int node_num = 0;
    for (int i = 0; i < SIZE; i++) {
        if (p->next[i] == NULL) continue;
        node_num += search(p->next[i]);
    }
    return node_num + 1;
}
 
int main() {
    Trie tree = new_node();
    char *str = (char *)malloc(N * sizeof(char));
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        insert(tree, str + i);
    }
    printf("%d\n", search(tree) - 1);
    clear(tree);
    free(str);
    return 0;
}
