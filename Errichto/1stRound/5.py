# Given a sequence of length N (N <= 10^5), find the longest consecutive subsequence (a segment of elements) where all elements are different

n = int(input())
a = [int(i) for i in input().split(' ')]

s = set()

i = j = 0

m = 0
while j < n:
    if a[j] not in s:
        s.add(a[j])
        j += 1
    else:
        while a[i] != a[j]:
            s.remove(a[i])
            i += 1
        i += 1
        j += 1
    if j - i > m:
        m = j - i

print(m)
