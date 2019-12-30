def go():
    x, y, z = [int(i) for i in input().split(' ')]
    answer = z * 2 + 2 * min(x, y)
    if x == y:
        return answer
    return answer + 1

print(go())
