n = int(input())
s = sum(int(i) for i in input().split(' '))
answer = abs(s - n)
base = 1
for b in range(2, 1000000):
    s_in_b = (b ** n - 1) // (b - 1)
    diff = abs(s - s_in_b)
    if diff < answer:
        answer = diff
        base = b
print(base, answer)
