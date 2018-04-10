#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *front;
}Node, *LinkedList;


Node insert(LinkedList head, int data, int index) {
	Node *p, ret;
	int raw_index = index, len = 0;
	p = head;
	ret.data = 0;
	while (p && index) {
		p = p->next;
		++len;
		--index;
		if (p == head) break;
	}
	//if (p == NULL) {
	//	ret.data = ERROR;
	//	free(current_node); 	
	//}
	if (index == 0) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = data;
		node->next = node;
		if (p != NULL) {
			node->next = p->next;
			p->next = node;
		}
		node->front = NULL;
		if (p == head && len == raw_index) {
			head = node;
		}
		ret.data = 1;
	}
	ret.next = head;
	return ret;
}

LinkedList round(LinkedList head) {
	Node *fir ,*sec;
	if (head == NULL) {
		return head;
	}
	fir = head;
	sec = head->next;
	while (sec != head->next) {
		sec->front = fir;
		fir = fir->next;
		sec = sec->next;
	}
	return head;
}

void output(LinkedList head, int flag) {
	int length = 0;
    Node *p = head, *q;
    while (p->data != flag) {
        p = p->next;
    }
    q = p;
    printf("%d", p->data);
    p = p->front;
    while (p != q) {
    	printf(" %d", p->data);
    	p = p->front;
    }
    printf("\n");
    return;
}

void clear(LinkedList head) {
	Node *flag, *p = head->next;
	head->next = NULL;
	while (p) {
		flag = p->next;
		free(p);
		p = flag;
	}
	return ;
}

int main() {
	LinkedList linkedlist = NULL;
	Node ret;
	int n, data, flag;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data);
		ret = insert(linkedlist, i, data);
		if (ret.data == 0) {
			printf("ERROR\n");
			return 1;
		}
		linkedlist = ret.next;
	}	
	linkedlist = round(linkedlist);
	scanf("%d", &flag);
	output(linkedlist, flag);
	fflush(stdout);
	clear(linkedlist);
	return 0;
}
