h, w = [int(i) for i in input().split(' ')]

m = []
for i in range(h):
    m.append(input())

def valid(d):
    global h, w
    return 0 <= d[0] and d[0] < h and 0 <= d[1] and d[1] < w

def bfs(i, j):
    global m
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    index = 0
    q = [(i, j)]
    v = {(i, j): 0}
    while index < len(q):
        item = q[index]
        for d in dirs:
            new_item = (d[0] + item[0], d[1] + item[1])
            if valid(new_item) and m[new_item[0]][new_item[1]] == '.' and new_item not in v:
                v[new_item] = v[item] + 1
                q.append(new_item)
        index += 1
    return max(v.values())

answer = 0

for i in range(h):
    for j in range(w):
        if m[i][j] == '.':
            answer = max(answer, bfs(i, j))

print(answer)
