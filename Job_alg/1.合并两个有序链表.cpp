#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* mergeTwoSortedLinkList(ListNode *head1, ListNode *head2) {
    ListNode *p[2], *q, *ret;
    ret = (ListNode *)malloc(sizeof(ListNode));
    p[0] = head1;
    p[1] = head2;
    q = ret;
    int ind;
    while (p[0] != NULL || p[1] != NULL) {
        if (p[1] == NULL) {
            ind = 0;
        } else if (p[0] == NULL) {
            ind = 1;
        } else {
            ind = (p[0]->val < p[1]->val ? 0 : 1);
        }
        q->next = p[ind];
        p[ind] = p[ind]->next;
        q = q->next;
        q->next = NULL;
    }
    q = ret->next;
    free(ret);
    return q;
}



int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head2;
    head2 = head2->next;
    free(temp);
    head = mergeTwoSortedLinkList(head, head2);
    temp = head;
    while (head) {
        printf("%d ", head->val);
        head = head->next;
        free(temp);
        temp = head;
    }
    printf("\n");
    return 0;
}