#!/usr/bin/env python3
# https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list
def reverse(head):
    l=DoublyLinkedList()
    def loop(n):
        if n == None: return
        loop(n.next)
        l.insert_node(n.data)
    loop(head)
    return l.head
