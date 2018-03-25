
// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list
Node* SortedInsert(Node *head,int data) {
	Node *newNode = new Node();
	newNode->data = data;
	if (head == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
	if (head->data > newNode->data) {
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = NULL;
		return newNode;
	}
	Node* current = head;
	while (current->next && current->next->data <= newNode->data) current = current->next;
	newNode->prev = current;
	if (current->next) {
		current->next->prev = newNode;
		newNode->next = current->next;
		newNode->prev = current;
		current->next = newNode;
	} else {
		current->next = newNode;
		newNode->next = NULL;
		newNode->prev = current;
	}
	return head;
}
