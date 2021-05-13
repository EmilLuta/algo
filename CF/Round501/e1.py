def go():
    n, m = [int(i) for i in input().split(' ')]
    grid = []
    count = 0
    for _ in range(n):
        l = [i for i in input()]
        count += l.count('*')
        grid.append(l)

    visited = set()
    stars = set()

    def x(i, j):
        low = i - 1
        high = i + 1
        while -1 < low < n and -1 < high < n and grid[low][j] == grid[high][j] == '*':
            low -= 1
            high += 1
        low += 1
        high -= 1
        left = j - 1
        right = j + 1
        while -1 < left < m and -1 < right < m and grid[i][left] == grid[i][right] == '*':
            left -= 1
            right += 1
        left += 1
        right -= 1
        z = min((high - low) // 2, (right - left) // 2)
        if z > 0:
            stars.add((i + 1, j + 1, z))
            visited.add((i, j))
            for k in range(z + 1):
                visited.add((i, j - k))
                visited.add((i, j + k))
                visited.add((i - k, j))
                visited.add((i + k, j))

    for i in range(n):
        for j in range(m):
            if grid[i][j] == '*':
                x(i, j)
    if len(visited) != count:
        print(-1)
    else:
        print(len(stars))
        for star in stars:
            print(' '.join(str(i) for i in star))

go()
