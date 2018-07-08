# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if head.next is None:
            return head
        prev = head
        current = head.next
        prev.next = None
        while current.next:
            to_come = current.next
            current.next = prev
            prev = current
            current = to_come
        current.next = prev
        return current
