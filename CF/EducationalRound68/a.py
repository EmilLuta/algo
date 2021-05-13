def go():
    n, x = [int(i) for i in input().split(' ')]
    return 2 * x
t = int(input())
for _ in range(t):
    print(go())
