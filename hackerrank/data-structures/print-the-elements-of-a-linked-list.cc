// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list
void Print(Node *head) {
	if (head) {
		std::cout << head->data << std::endl;;
		Print(head->next);
	}
}
