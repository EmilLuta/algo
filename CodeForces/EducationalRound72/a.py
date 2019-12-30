def bs(s, i, e):
    low = 0
    high = e + 1
    while low < high:
        mid = (low + high) // 2
        if s - mid > i + mid:
            low = mid + 1
        else:
            high = mid
    return low


t = int(input())
output = ''
for _ in range(t):
    s, i, e = [int(x) for x in input().split(' ')]
    s += e
    output += f'{bs(s, i, e)}\n'
print(output)
