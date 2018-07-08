# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        q = [root, None]
        while len(q) > 1:
            q_t = []
            for i in range(len(q) - 1):
                q[i].next = q[i + 1]
                if q[i].left:
                    q_t.append(q[i].left)
                if q[i].right:
                    q_t.append(q[i].right)
            q_t.append(None)
            q = q_t

root = TreeLinkNode(0)
Solution().connect(root)
