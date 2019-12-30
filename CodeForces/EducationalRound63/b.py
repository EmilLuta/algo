def go():
    n = int(input())
    a = [int(i) for i in input()]
    a = a[:n - 10]
    x = a.count(8)
    z = n - 10
    if z // 2 + 1 <= x:
        return "YES"
    return "NO"

print(go())
