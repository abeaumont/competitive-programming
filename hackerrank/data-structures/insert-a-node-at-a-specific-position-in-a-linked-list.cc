// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
Node* InsertNth(Node *head, int data, int position) {
  Node *newNode = new Node;
  newNode->data = data;
  if (position == 0) {
    newNode->next = head;
    return newNode;
  }
  Node *current = head;
  for(int i = 1; i < position; i++) current = current->next;
  newNode->next = current->next;
  current->next = newNode;
  return head;
}
