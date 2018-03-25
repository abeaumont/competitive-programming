#!/usr/bin/env python2
# https://www.hackerrank.com/challenges/ctci-linked-list-cycle
def has_cycle(head):
    s = set()
    while head:
        if head in s: return True
        s.add(head)
        head = head.next
    return False
