# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        if root is None:
            return 0
        parents = {}
        parents[root] = 0
        queue = [root]
        i = 0
        odds = 0
        evens = root.val
        while i < len(queue):
            item = queue[i]
            i += 1
            if item.left != None:
                parents[item.left] = parents[item] + 1
                queue.append(item.left)
                if parents[item.left] % 2 == 0:
                    evens += item.left.val
                else:
                    odds += item.left.val
            if item.right != None:
                parents[item.right] = parents[item] + 1
                queue.append(item.right)
                if parents[item.right] % 2 == 0:
                    evens += item.right.val
                else:
                    odds += item.right.val
        print(root)
        import code
        code.interact(local=dict(globals(), **locals()))
        return max(odds, evens)
        

r = TreeNode(4)
l1 = TreeNode(1)
l2 = TreeNode(2)
l3 = TreeNode(3)
r.left = l1
l1.left = l2
l2.left = l3

print(Solution().rob(r))
