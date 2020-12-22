'''
Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false.

 

Example 1:


Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
Output: true
Explanation: The second player can choose the node with value 2.
 

Constraints:

root is the root of a binary tree with n nodes and distinct node values from 1 to n.
n is odd.
1 <= x <= n <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _subtree(self, node, subtree, nodes):
        subtree[node.val] = 1
        nodes[node.val] = node
        if node.left is None and node.right is None:
            return
        if node.left is not None:
            self._subtree(node.left, subtree, nodes)
            subtree[node.val] += subtree[node.left.val]
        if node.right is not None:
            self._subtree(node.right, subtree, nodes)
            subtree[node.val] += subtree[node.right.val]
        
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        nodes = {}
        subtree = {}
        self._subtree(root, subtree, nodes)
        l = r = 0
        p = n - subtree[x]
        our_node = nodes[x]
        if our_node.left:
            l = subtree[our_node.left.val]
        if our_node.right:
            r = subtree[our_node.right.val]
        us = max(p, l, r)
        return us > n - us
