def go():
    n, h, m = map(int, input().split(' '))
    houses = [h] * n
    for _ in range(m):
        l, r, x = [int(w) for w in input().split(' ')]
        l -= 1
        r -= 1
        for i in range(l, r + 1):
            houses[i] = min(houses[i], x)
    answer = 0
    for i in range(n):
        answer += houses[i] ** 2

    return answer

print(go())
