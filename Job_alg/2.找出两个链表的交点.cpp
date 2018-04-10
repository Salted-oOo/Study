
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;
ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    ListNode *p, *q;
    int count, count1, count2;
    count1 = count2 = 1;
    p = head1;
    q = head2;
    while (p->next != NULL) {
        p = p->next;
        count1++;
    }
    printf("count1 : %d", count1);
    while (q->next != NULL) {
        q = q->next;
        count2++;
    }
    printf("count2 : %d", count2);



    if (p != q) return NULL;
    p = head1;
    q = head2;    
    if (count1 > count2) {
        count = count1 - count2;
        while (count--) {
            p = p->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
    }
    if (count2 > count1) {
        count = count2 - count1;
        while (count--) {
            q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    ListNode *ans = NULL;
    for (int i = 0; i < n; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
        if (i == x) {
            ans = temp;
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp->next = ans;
    temp = head2;
    head2 = head2->next;
    free(temp);
    temp = findIntersectionListNode(head, head2);
    if(temp == ans) {
        printf("Accept\n");
    } else {
        printf("Wrong answer\n");
    }
    return 0;
}