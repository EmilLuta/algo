from typing import List

# Definition for a binary tree node.
class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def delNodes(self, root: Node, to_delete: List[int]) -> List[Node]:
        to_delete_nodes = set(to_delete)
        out = []
        nodes = [root]
        parents = {root: None}
        i = 0
        while i < len(nodes):
            node = nodes[i]
            if parents[node] is None and node.val not in to_delete_nodes:
                out.append(node)
            if node.val in to_delete_nodes:
                if parents[node] is not None:
                    if parents[node].left is not None and parents[node].left.val == node.val:
                        parents[node].left = None
                    if parents[node].right is not None and parents[node].right.val == node.val:
                        parents[node].right = None
                if node.left is not None and node.left.val not in to_delete_nodes:
                    out.append(node.left)
                if node.right is not None and node.right.val not in to_delete_nodes:
                    out.append(node.right)
            if node.left is not None:
                nodes.append(node.left)
                parents[node.left] = node
            if node.right is not None:
                nodes.append(node.right)
                parents[node.right] = node
            i += 1
        return out

#             if node.left is not None:
#                 parents[node.left] = node
#                 nodes.append(node.left)
#                 if node.val in to_delete_nodes:
#                     if parents[node] is not None:
#                         if parents[node].right == node.val:
#                             parents[node].right = None
#                         if parents[node].left == node.val:
#                             parents[node].left = None
#                     out.append(node.left)

#             if node.right is not None:
#                 parents[node.right] = node
#                 nodes.append(node.right)
#                 if node.val in to delete_nodes:
#                     if parents[node] is not None:
#                         if parents[node].right == node.val:
#                             parents[node].right = None
#                         if parents[node].left == node.val:
#                             parents[node].right = None
#                     if node.right is not None:
#                         out.append(node.right)


#             if new_node is not None:
#                 nodes.append(new_node)
#                 if node.val in to_delete_nodes:
#                     node.right = None
#                     node.left = None
#                     if parents[node].val == node.val
#                     out.append(new_node)
#             i += 1
#         return out

seven = Node(7)
six = Node(6)
five = Node(5)
four = Node(4)
three = Node(3)
three.left = six
three.right = seven
two = Node(2)
two.left = four
two.right = five
one = Node(1)
one.left = two
one.right = three

Solution().delNodes(one, [3, 5])
