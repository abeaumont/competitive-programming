// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle
bool has_cycle(Node* head) {
	if (head == NULL) return false;
	if (head->next == NULL) return false;
	Node* a = head;
	Node* b = head->next;
	while (a != b) {
		if (a->next == NULL) return false;
		a = a->next;
		if (b->next == NULL) return false;
		if (b->next->next == NULL) return false;
		b = b->next->next;
	}
	return true;
}
