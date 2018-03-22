// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail
int GetNode(Node *head,int positionFromTail) {
	Node *current = head;
	for(int i = 0; i < positionFromTail; i++) current = current->next;
	if (current->next == NULL) return head->data;
	return GetNode(head->next, positionFromTail);
}
