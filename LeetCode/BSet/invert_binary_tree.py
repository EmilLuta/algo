# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        q = [root]
        while q:
            current = q.pop(0)
            if current:
                current.left, current.right = current.right, current.left
                q.append(current.left)
                q.append(current.right)
        return root
