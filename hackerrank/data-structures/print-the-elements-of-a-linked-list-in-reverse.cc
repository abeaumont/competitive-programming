// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse
void ReversePrint(Node *head) {
	if (!head) return;
	ReversePrint(head->next);
	std::cout << head->data << std::endl;
}
