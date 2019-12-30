# N Q - size of array and the number of queries
# the array (N positive integers)
#
# queries of two types:
# "1 i x" -> change a[i] to x
# "2 L R" -> print the maximum value in interval [L, R]

import math

n, q = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

size = round(math.sqrt(n))
buckets = n // size + 1
s = [float('-inf')] * buckets

def get_bucket(i):
    return i // size

for i in range(n):
    bucket = get_bucket(i)
    s[bucket] = max(a[i], s[bucket])

for _ in range(q):
    v, l, r = [int(i) for i in input().split(' ')]
    if v == 1:
        a[i] = r
        bucket_id = get_bucket(l)
        m = float('-inf')
        for i in range(bucket_id * size, min(n, bucket_id * (size + 1))):
            m = max(m, a[i])
        s[bucket_id] = m
    elif v == 2:
        first_bucket = get_bucket(l)
        second_bucket = get_bucket(r)
        if first_bucket == second_bucket:
            m = float('-inf')
            for i in range(i, r + 1):
                m = max(m, a[i])
        else:
            m = float('-inf')
            for i in range(first_bucket + 1, second_bucket):
                m = max(m, s[i])
            i = l
            bucket_l = get_bucket(l)
            while bucket_l == get_bucket(i):
                m = max(m, a[i])
                i += 1
            i = r
            bucket_r = get_bucket(r)
            while bucket_r == get_bucket(i):
                m = max(m, a[i])
                i -= 1
        print(m)
