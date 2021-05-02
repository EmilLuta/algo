# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        output = []
        if root is None:
            return output
        q = [root]
        while q:
            o = []
            n_q = []
            while q:
                c = q.pop(0)
                if c:
                    n_q.append(c.left)
                    n_q.append(c.right)
                    o.append(c.val)
            if o:
                output.append(o)
            q = n_q
        return output

root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
print(Solution().levelOrder(root))
