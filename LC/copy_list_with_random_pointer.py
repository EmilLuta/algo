class Node:
    def __init__(self, val, n = None, r = None):
        self.val = val
        self.next = n
        self.random = r

class Solution(object):
    def copyRandomList(self, head):
        if head is None:
            return
        node = head
        while node is not None:
            new_node = Node(node.val)
            new_node.next = node.next
            node.next = new_node
            node = new_node.next
        node = head
        new_head = head.next
        while node is not None:
            new_node = node.next
            if node.random is not None:
                new_node.random = node.random.next
            node = node.next.next
        node = head
        while node.next.next:
            first = node
            second = node.next
            third = node.next.next
            fourth = node.next.next.next
            second.next = fourth
            first.next = third
            node = third
        node.next = None
        return new_head










    def copyRandomList1(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return
        new_head = Node(head.val, None, None)
        current_new_node = new_head
        current_node = head.next
        n_map = {head: current_new_node}
        while current_node is not None:
            node = Node(current_node.val)
            current_new_node.next = node
            current_new_node = current_new_node.next
            n_map[current_node] = current_new_node
            current_node = current_node.next
        node = head
        new_node = new_head
        while node is not None:
            if node.random is not None:
                new_node.random = n_map[node.random]
            node = node.next
            new_node = new_node.next
        return new_head

# [[7,null],[13,0],[11,4],[10,2],[1,0]]
one = Node(7, None, None)
two = Node(13, None, None)
three = Node(11, None, None)
four = Node(10, None, None)
five = Node(1, None, None)
one.next = two
two.next = three
two.random = one
three.next = four
three.random = five
four.next = five
four.random = three
five.random = one

node = one
while node:
    if node.random:
        print(f'At node {[node.val, node.random.val]}')
    else:
        print(f'At node {[node.val, None]}')
    node = node.next

print('===')

Solution().copyRandomList(one)
