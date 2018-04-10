#include <time.h>
#include <stdlib.h>
#include <stdio.h>
 
#define ERROR 0
#define OK 1
 
typedef struct node {
    int data;
    struct node *next;
} node, *LinkedList;
 
node *get_node(int data) {
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}
 
node insert(LinkedList head, int index, int n) {
    node *new_node = get_node(n);
    node ret;
    ret.next = head;
    node *p = &ret;
    while (p && index--) {
        p = p->next;
    }
    if (p == NULL) {
        ret.data = ERROR;
        free(new_node);
    } else {
        new_node->next = p->next;
        p->next = new_node;
        ret.data = OK;
    }
    return ret;
}
 
node delete_node(LinkedList head, int index) {
    node *p, *q;
    node ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && index--) {
        p = p->next;
        q = q->next;
    }
    if (q == NULL) {
        ret.data = ERROR;
    } else {
        p->next = q->next;
        free(q);
        ret.data = OK;
    }
    return ret;
}
 
void clear(LinkedList head) {
    node *p = head, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
}
 
void output(LinkedList head) {
    node *p = head;
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
 
int main() {
    srand(time(0));
    LinkedList head = NULL;
    node ret;
    for (int i = 0; i < 10; i++) {
        ret = insert(head, i, rand() % 100 + 1);
        head = ret.next;
    }
    output(head);
    int n;
    while (scanf("%d", &n) != EOF) {
        ret = delete_node(head, n);
        head = ret.next;
        output(head);
    }
    return 0;
}
 