n, m, ta, tb, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]
b = [int(i) for i in input().split(' ')]

def how_far(i, j, ta, tb):
    global m
    while j < m and a[i] + ta > b[j]:
        j += 1
    # import code
    # code.interact(local=dict(globals(), **locals()))
    return j

def get_ans(i, j, ta, tb):
    global n, m
    if i >= n or j >= m:
        return (i, j, -1)
    h = how_far(i, j, ta, tb)
    ans = [i, h, b[h] + tb]
    if a[i] + ta > b[h]:
        ans[2] = -1
    return ans


def go():
    global n, m, ta, tb, k
    if k >= n or k >= m:
        return -1
    i = j = 0
    h = how_far(i, j, ta, tb)
    value = None
    # import code
    # code.interact(local=locals())
    if h >= m:
        return -1
    if a[i] + ta > b[h]:
        return -1
    for _ in range(k):
        ans_i = get_ans(i + 1, j, ta, tb)
        ans_j = get_ans(i, j + 1, ta, tb)
        # import code
        # code.interact(local=dict(globals(), **locals()))
        if ans_j[2] == -1:
            return -1
        prev_i, prev_j = i, j
        if ans_i[2] >= ans_j[2]:
            i, j, value = ans_i
        else:
            i, j, value = ans_j
        if i == prev_i and j == prev_j:
            return -1
        # import code
        # code.interact(local=dict(globals(), **locals()))
    return value
print(go())
