// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists
int FindMergeNode(Node *headA, Node *headB) {
	Node* currentA = headA;
	while (currentA != NULL) {
		Node* currentB = headB;
		while (currentB != NULL) {
			if (currentA == currentB) return currentA->data;
			currentB = currentB->next;
		}
		currentA = currentA->next;
	}
}
