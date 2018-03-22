// https://www.hackerrank.com/challenges/reverse-a-linked-list
Node* Reverse(Node *head) {
	if (!head) return NULL;
	Node *next = head->next;
	Node *newHead = head;
	if (next) {
		newHead = Reverse(next);
		next->next = head;
		head->next = NULL;
	}
	return newHead;
}
