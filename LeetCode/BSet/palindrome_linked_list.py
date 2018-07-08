# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return True
        slow = prev = fast = head
        while fast and fast.next:
            fast = fast.next.next
            keep = slow.next
            slow.next = prev
            prev = slow
            slow = keep
        head.next = None
        if fast is None:
            forward = slow
        else:
            forward = slow.next
        backward = prev
        while forward:
            if forward.val != backward.val:
                return False
            forward = forward.next
            backward = backward.next
        return True


root = ListNode(1)
root.next = ListNode(2)
# root.next.next = ListNode(2)
# root.next.next.next = ListNode(1)

print(Solution().isPalindrome(root))
