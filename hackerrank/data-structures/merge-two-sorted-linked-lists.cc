// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists
Node* MergeLists(Node *headA, Node* headB) {
	if (headA == NULL && headB == NULL) return NULL;
	if (headA == NULL) return headB;
	if (headB == NULL) return headA;
	if (headA->data < headB->data) {
		headA->next = MergeLists(headA->next, headB);
		return headA;
	}
	headB->next = MergeLists(headA, headB->next);
	return headB;
}
