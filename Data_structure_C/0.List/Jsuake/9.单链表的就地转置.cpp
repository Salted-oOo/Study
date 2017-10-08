#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Node {
	char data;
	struct Node *next;
}Node, *LinkedList;

Node *create_node(char data) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	return p;
}

Node insert(LinkedList head, char data, int index) {
	Node *current_node = create_node(data);
	Node ret;
	ret.data = 0;
	ret.next = head;
	Node *p = &ret;
	while (p->next && index--) {
		p = p->next;
	}
	if (p == NULL) {
		ret.data = ERROR;
		free(current_node); 	
	}else {
		current_node->data = data;
		current_node->next = p->next;
		p->next = current_node;
		ret.data = OK;  
	}
	return ret;
}

LinkedList reverse(LinkedList head) {
	if (head == NULL) {
		return head;
	}
	Node *current_node, *next_node;
	current_node = head->next;
	head->next = NULL;
	while (current_node != NULL) {
		next_node = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = next_node;
	}
	return head;
}

void output(LinkedList head) {
	int length = 0;
    Node *p = head;
    if (p) {
        printf("%c", p->data);
        p = p->next;
    }
    while (p) {
    	printf(" %c", p->data);
    	p = p->next;
    }
    printf("\n");
}

void clear(LinkedList head) {
	Node *flag, *p = head;
	while (p) {
		flag = p->next;
		free(p);
		p = flag;
	}
	return ;
}

int main() {
	LinkedList head = NULL;
	Node ret;
	int n;
	char data;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%c", &data);
		if(i != n -1) {
			scanf(" ");
		}
		ret = insert(head, data, i);
		head = ret.next;
	}
	head = reverse(head);
	output(head);
	clear(head);
	return 0;
}
