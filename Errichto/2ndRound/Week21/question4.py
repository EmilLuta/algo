'''
Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:

Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".
Example 2:

Input: root = [1,2,3,4]
Output: [4]
Example 3:

Input: root = [1,2,3,4,5]
Output: [2,4,5]
 

Constraints:

The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        levels = {root: 0}
        parents = {root: None}
        queue = [root]
        index = 0
        while index < len(queue):
            node = queue[index]
            index += 1
            if node.left:
                queue.append(node.left)
                levels[node.left] = levels[node] + 1
                parents[node.left] = node
            if node.right:
                queue.append(node.right)
                levels[node.right] = levels[node] + 1
                parents[node.right] = node
        deepest_level = max(levels.values())
        deepest_nodes = []
        for node in levels:
            if levels[node] == deepest_level:
                deepest_nodes.append(node)
        node = deepest_nodes[0]
        lowest_ancestors = set()
        while node is not None:
            lowest_ancestors.add(node)
            node = parents[node]
        lowest_ancestor = deepest_nodes[0]
        for i in range(1, len(deepest_nodes)):
            node = deepest_nodes[i]
            while node not in lowest_ancestors:
                node = parents[node]
            lowest_ancestor = node
        return lowest_ancestor

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        left tells me -> I found out that vertex X is the answer
        right tells me -> I found out that vertex Y is the answer
        if left_depth == right_depth:
            return (root, left_depth + 1)
        if left_depth > right_depth:
            return (X, left_depth + 1)
