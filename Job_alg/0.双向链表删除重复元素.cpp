ListNode* deletenode(ListNode *head, int val) {
	if (head == NULL) return NULL;
	ListNode *ret = (ListNode*)malloc(sizeof(ListNode));
	ret->next = head;
	ret->pre = NULL;
	head->pre = ret;
	ListNode *p, *q;
	p = head;
	while (p) {
		if (p->val == val) {
			if (p->next != NULL) {
				p->next->pre = p->pre;
			}
			p->pre->next = p->next;
			q = p;
			p = p->next;
			free(q);
		} else {
			p = p->next;
		}
	}
	head = ret->next;
	if (head) {
		head->pre = NULL;
	}
	free(ret);
	return head;
}

ListNode* twoWayLinkListUnique(ListNode *head) {
	if (head == NULL) return NULL;
	ListNode *q, *p;
	p = head;
	while (p) {
		q = deletenode(p->next, p->val);
		if (q) {
			q->pre = p;
		}
		p->next = q;
		p = p->next;
	}
	return head;
}