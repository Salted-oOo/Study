#include <stdio.h>
#include <stdlib.h>
#include "test.h"
 
#define ERROR 0
#define OK 1
 
typedef struct Node {
    int data;
    struct Node *next;
} LinkedList, *pLinkedList;
 
pLinkedList create_node(int data) {
    pLinkedList p = (pLinkedList)malloc(sizeof(LinkedList));
    p->data = data;
    p->next = NULL;
    return p;
}
 
pLinkedList insert(pLinkedList head, pLinkedList new_node, int index) {
    LinkedList ret;
    pLinkedList p;
    ret.next = head;
    p = &ret;
    while (index > 0 && p != NULL) {
        p = p->next;
        index--;
    }
    if (p == NULL) {
        return ret.next;
    }
    new_node->next = p->next;
    p->next = new_node;
    return ret.next;
}
 
pLinkedList search(pLinkedList head, int x) {   
    pLinkedList p = head;
    while (p) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }
    return p;
}
 
pLinkedList delete_node(pLinkedList head, int x) {

    pLinkedList p, q;
    LinkedList ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && q->data != x) {
        p = p->next;
        q = q->next;
    }
    if (q) {
        p->next = q->next;
        free(q);
    }
    return ret.next;
}
pLinkedList modify(pLinkedList head, int index, int x) {
    pLinkedList p = head;
    while (p && index) {
        p = p->next;
        --index;
    }
    if (p) {
        p->data = x;
    }
    return head;
}
 
int main() {
    return 0;
}
 
TEST(LinkedList, insert_head) {
    pLinkedList p, head = NULL;
    for (int i = 0; i < 10; i++) {
        p = create_node(i);
        head = insert(head, p, 0);
        ASSERT_EQ(head, p);
    }
}
 
TEST(LinkedList, insert_tail) {
    pLinkedList p, head = NULL, q = NULL;
    for (int i = 0; i < 10; i++) {
        p = create_node(i);
        head = insert(head, p, i);
        if (q == NULL) {
            q = head;
        } else {
            q = q->next;
        }
        ASSERT_EQ(q, p);
    }
}

TEST(LinkedList, search_node) {
    pLinkedList p, head = NULL, q = NULL;
    int j = 0;
    for(int i = 0; i < 10; i++,j++) {
        p = create_node(i);
        head = insert(head, p, i);
        if (q == NULL) {
            q = head;
        } else {
            q = q->next;
        }        
      //  y = search(q, i);
      //  ASSERT_EQ(y->data, j);
        ASSERT_EQ(q->data, j);
    }
}

TEST(LinkedList, delete_node) {
    pLinkedList p, head = NULL, q = NULL, t = NULL;
    for(int i = 0; i < 10; i++) {
        p = create_node(i);
        head = insert(head, p, i);
    }
    for(int j = 0; j < 5; j++) {
        delete_node(head, j + 2);
        q = search(head, j + 2);        
        //if (q == NULL) {
        //    q = head;
        //} else {
         //   q = q->next;
        //} 
        ASSERT_EQ(q, t);
    }
}