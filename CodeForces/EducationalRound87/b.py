from bisect import bisect

t = int(input())
out = ''
while t > 0:
    t -= 1
    s = input()
    n = len(s)
    answer = float('inf')
    keep = [[], [], []]
    for i in range(n):
        keep[int(s[i]) - 1].append(i)
    for i in range(1, n - 1):
        a = (int(s[i]) - 2) % 3
        b = (int(s[i])) % 3
        in_a = bisect(keep[a], i)
        in_b = bisect(keep[b], i)
        if len(keep[a]) != in_a and in_b > 0:
            answer = min(answer, abs(keep[a][in_a] - i) + abs(keep[b][in_b - 1] - i) + 1)
        if in_a > 0 and len(keep[b]) != in_b:
            answer = min(answer, abs(keep[a][in_a - 1] - i) + abs(keep[b][in_b] - i) + 1)
    out += f'{answer if answer != float("inf") else 0}\n'
print(out)
