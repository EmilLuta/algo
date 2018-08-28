class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(node):
    if node is None:
        return '#'
    return '{} {} {}'.format(node.val, serialize(node.left), serialize(node.right))


def deserialize(s):
    a = s.split(' ')
    def go():
        if len(a) != 0:
            x = a.pop(0)
            if x is None:
                return None
            n = Node(x)
            n.left = go()
            n.right = go()
            return n
    return go()
