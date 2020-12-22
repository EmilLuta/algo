class Stack:
    def __init__(self):
        self.stack = []
    def add(self, x):
        self.stack.append(x)
    def pop(self):
        return self.stack.pop()
    def __len__(self):
        return len(self.stack)
    def peek(self):
        return self.stack[len(self.stack) - 1]
    def is_empty(self):
        return len(self.stack) == 0
def is_match(p1, p2):
    if p1 == "(" and p2 == ")":
        return True
    return False
def paren_balanced(p_string):
    s = Stack()
    is_equal = True
    index = 0
    while index < len(p_string) and is_equal:
        paren = p_string[index]
        if paren in "(":
            s.add(paren)
        else:
            if s.is_empty():
                is_equal = False
            else:
                top = s.pop()
                if not is_match(top, paren):
                    is_equal = False
        index += 1
    if s.is_empty() and is_equal:
        return True
    return False
print(paren_balanced("()()()"))
print(paren_balanced(")()()("))
