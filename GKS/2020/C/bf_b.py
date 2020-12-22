from collections import defaultdict
from copy import deepcopy

def solve(h, w, m):
    go_to = defaultdict(set)
    for r in range(h - 2, -1, -1):
        for c in range(w):
            go_to[m[r + 1][c]].add(m[r][c])
    answer = ''
    cycle = False
    while len(go_to) > 0 and not cycle:
        cycle = True
        for letter in go_to:
            found = True
            for c in go_to:
                if c == letter:
                    continue
                if letter in go_to[c]:
                    found = False
                    break
            if found:
                cycle = False
                answer += letter
                go_to.pop(letter)
                break
    if cycle:
        return -1
    for r in range(h):
        for c in range(w):
            if m[r][c] not in answer:
                answer += m[r][c]
    return answer


def go(h, w, m):
    s = set()
    for r in range(h):
        for c in range(w):
            s.add(m[r][c])
    LIMIT = len(s)
    count = 0
    answer = ''
    while len(s) > 0 and count <= LIMIT + 1:
        l = s.pop()
        n_m = deepcopy(m)
        ok = True
        for r in range(h - 1, -1, -1):
            for c in range(w):
                if m[r][c] == l:
                    if r == h - 1:
                        n_m[r][c] = None
                        continue
                    if n_m[r + 1][c] is None:
                        n_m[r][c] = None
                    else:
                        ok = False
        if ok:
            m = deepcopy(n_m)
            count = 0
            answer += l
        else:
            s.add(l)
            count += 1
    if count > LIMIT + 1:
        return -1
    return answer

def checker(h, w, m, answer):
    for l in answer:
        for r in range(h):
            for c in range(w):
                if m[r][c] == l:
                    m[r][c] = None
        for r in range(h - 1):
            for c in range(w):
                if m[r][c] is None and m[r + 1][c] is not None:
                    return False
    return True
assert checker(4, 6, [['Z', 'O', 'A', 'A', 'M', 'M'], ['Z', 'O', 'A', 'O', 'M', 'M'], ['Z', 'O', 'O', 'O', 'O', 'M'], ['Z', 'Z', 'Z', 'Z', 'O', 'M']], 'ZOAM') is True
assert checker(4, 6, [['Z', 'O', 'A', 'A', 'M', 'M'], ['Z', 'O', 'A', 'O', 'M', 'M'], ['Z', 'O', 'O', 'O', 'O', 'M'], ['Z', 'Z', 'Z', 'Z', 'O', 'M']], 'ZOMA') is True
assert checker(4, 6, [['Z', 'O', 'A', 'A', 'M', 'M'], ['Z', 'O', 'A', 'O', 'M', 'M'], ['Z', 'O', 'O', 'O', 'O', 'M'], ['Z', 'Z', 'Z', 'Z', 'O', 'M']], 'ZMAO') is False
h = 5
w = 2
from itertools import product
for y in [[list(i[x:x+w]) for x in range(0, len(i), w)] for i in product("ABCDE", repeat=w*h)]:
    # bf = go(h, w, y)
    smart = solve(h, w, y)
    if smart != -1 and not checker(h, w, y, smart):
        print(y, smart)
    # if bf != smart:
    # if (bf == -1 or smart == -1) and bf != smart:
        # for x in y:
            # print(x)
        # print(bf)
        # print(smart)
