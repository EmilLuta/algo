def balanced_brackets(s):
    stack = []
    for l in s:
        if l == ')':
            if len(stack) == 0:
                return False
            opening = stack.pop()
            if opening != '(':
                return False
        elif l == ']':
            if len(stack) == 0:
                return False
            opening = stack.pop()
            if opening != '[':
                return False
        elif l == '}':
            if len(stack) == 0:
                return False
            opening = stack.pop()
            if opening != '{':
                return False
        else:
            stack.append(l)
    if len(stack) == 0:
        return True
    return False
