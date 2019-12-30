# Given a sequence of numbers (N ≤ 10^5), find two numbers that differ by exactly 1.


n = int(input())
a = [int(i) for i in input().split(' ')]

s = set()

for i in a:
    if i - 1 in s:
        print('Pair {} {}'.format(i, i - 1))
    if i + 1 in s:
        print('Pair {} {}'.format(i, i + 1))
    s.add(i)
