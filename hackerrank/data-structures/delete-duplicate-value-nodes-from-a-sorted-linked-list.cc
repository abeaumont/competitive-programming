// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list
Node* RemoveDuplicates(Node *head) {
	if (head == NULL) return NULL;
	while(head->next && head->data == head->next->data)
		head->next = head->next->next;
	RemoveDuplicates(head->next);
	return head;
}
