def go():
    t, sx, sy, ex, ey = [int(i) for i in input().split(' ')]
    a = input()
    x_dist = ex - sx
    y_dist = ey - sy
    d = {
        'N': 0,
        'S': 0,
        'E': 0,
        'W': 0
    }
    if x_dist < 0:
        d['W'] = -x_dist
    else:
        d['E'] = x_dist
    if y_dist < 0:
        d['S'] = -y_dist
    else:
        d['N'] = y_dist
    to_go = sum(d.values())
    gone = 0
    for i in a:
        if to_go == 0:
            return gone
        if d[i] > 0:
            d[i] -= 1
            to_go -= 1
        gone += 1
    if to_go == 0:
        return gone
    return -1

print(go())
