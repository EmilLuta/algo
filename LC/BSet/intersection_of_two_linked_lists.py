# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        a = headA
        b = headB
        if a is None or b is None:
            return
        while a is not b:
            a = a.next if a else headB
            b = b.next if b else headA
        return a

headA = ListNode(3)
headB = ListNode(2)
headB.next = headA

print(Solution().getIntersectionNode(headA, headB))
