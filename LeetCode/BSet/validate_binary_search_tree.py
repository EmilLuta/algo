# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        q = [(root, float('inf'), float('-inf'))]
        while q:
            current, minn, maxx = q.pop(0)
            if current:
                if current.val <= maxx or current.val >= minn:
                    return False
                q.append((current.left, min(minn, current.val), maxx))
                q.append((current.right, minn, max(maxx, current.val)))
        return True

node = TreeNode(10)
node.left = TreeNode(5)
node.right = TreeNode(15)
node.right.left = TreeNode(6)
node.right.right = TreeNode(20)

root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)

print(Solution().isValidBST(node))
