def go():
    n = int(input())
    a = set(int(i) for i in input().split(' '))
    for i in range(1, n + 2):
        if i not in a:
            return i

print(go())
