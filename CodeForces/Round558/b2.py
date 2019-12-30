def go():
    n = int(input())
    x = 10 ** 5 + 5
    colors = [0] * x
    count = [0] * x
    m = 0
    answer = 0
    for i, c in enumerate(input().split(' ')):
        color = int(c)
        index = i + 1
        colors[color] += 1
        count[colors[color] - 1] -= 1
        count[colors[color]] += 1
        m = max(m, colors[color])
        if count[1] == index:
            answer = index
        elif count[index] == 1:
            answer = index
        elif count[1] == 1 and m * count[m] == index - 1:
            answer = index
        elif count[m - 1] * (m - 1) == index - m and count[m] == 1:
            answer = index
    return answer

print(go())
