// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list
Node* Delete(Node *head, int position) {
  if (position == 0) return head->next;
  Node *current = head;
  for (int i = 1; i < position; i++) current = current->next;
  current->next = current->next->next;
  return head;
}
