// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list
Node* Insert(Node *head,int data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	if (head) {
		Node *current = head;
		while(current->next) current = current->next;
		current->next = newNode;
	} else {
		head = newNode;
	}
	return head;
}
