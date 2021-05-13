n, m = map(int, input().split(' '))
for i in range(n):
    s = list(input())
    for j in range(m):
        if s[j] == ".":
            s[j] = "B" if (i + j) % 2 else "W"
    print("".join(s))
