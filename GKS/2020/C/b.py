from collections import defaultdict

def solve():
    h, w = [int(i) for i in input().split(' ')]
    m = []
    for i in range(h):
        m.append(input())
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
t = int(input())
out = ''
for tc in range(1, t + 1):
    out += 'Case #{}: {}\n'.format(tc, solve())
print(out)
