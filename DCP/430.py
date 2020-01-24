from collections import deque

def fix_paranthesis(seq: str):
    new_seq = deque([])
    count = 0
    for p in seq:
        if p == '(':
            if count < 0:
                new_seq.extendleft('(' * (count * -1))
                count = 0
            count += 1
        if p == ')':
            count -= 1
        new_seq.append(p)
    if count < 0:
        new_seq.extendleft('(' * (count * -1))
    elif count > 0:
        new_seq.extend(')' * count)
    return ''.join(new_seq)

test_cases = [
    {
        'input': '((',
        'output': '(())',
    },
    {
        'input': '(()',
        'output': '(())',
    },
    {
        'input': '))()(',
        'output': '(())()()',
    },
    {
        'input': '))()(()))))',
        'output': '((((())()(()))))',
    },
    {
        'input': '((((',
        'output': '(((())))',
    },
    {
        'input': '(((())()((',
        'output': '(((())()(())))',
    },
    {
        'input': '((())()(()))))',
        'output': '((((())()(()))))'
    },
    {
        'input': '',
        'output': '',
    },
    {
        'input': ')',
        'output': '()',
    },
    {
        'input': '(',
        'output': '()',
    },
    {
        'input': '()',
        'output': '()',
    },
    {
        'input': '()()()',
        'output': '()()()',
    },
    {
        'input': '())((())))',
        'output': '((())((())))',
    },
    {
        'input': '())((())))(((((',
        'output': '((())((())))((((()))))',
    },
]

def test(func):
    for index, test_case in enumerate(test_cases):
        print(f'Running test case {index + 1}')
        assert func(test_case['input']) == test_case['output']
        print('OK')

test(fix_paranthesis)
