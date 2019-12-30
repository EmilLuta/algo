n = int(input())
r1, c1 = [int(i) for i in input().split(' ')]
r2, c2 = [int(i) for i in input().split(' ')]
r1 -= 1
r2 -= 1
c1 -= 1
c2 -= 1
m = [[int(i) for i in input()] for _ in range(n)]

def is_inside(i, j):
    if 0 <= i and i < n and 0 <= j and j < n:
        return True
    return False

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def explore_island(x, y):
    island = [(x, y)]
    for x1, y1 in island:
        for x2, y2 in directions:
            r, c = x1 + x2, y1 + y2
            if is_inside(r, c) and m[r][c] == 0:
                m[r][c] = 1
                island.append((r, c))
    return island

def distance(a, b):
    return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2

island_1 = explore_island(r1, c1)
if m[r2][c2] == 1:
    print(0)
else:
    island_2 = explore_island(r2, c2)
    m = float('inf')
    for i in island_1:
        for j in island_2:
            m = min(m, distance(i, j))
    print(m)
