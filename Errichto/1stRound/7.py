# Given a binary string and an integer K, find the shortest substring with exactly K ones.

#####
# 1 #
#####

# n, k = [int(i) for i in input().split(' ')]
# a = input()

# pre = [0]
# for i in range(n):
#     pre.append(pre[i])
#     if a[i] == '1':
#         pre[i + 1] += 1

# d = {}

# for i in range(n + 1):
#     d[pre[i]] = i

# m = float('inf')

# for i in range(n + 1):
#     if pre[i] >= k and pre[i] - k in d:
#         m = min(i - d[pre[i] - k], m)
# print(m if m is not float('inf') else 'Nope')

#####
# 2 #
#####
n, k = [int(i) for i in input().split(' ')]
a = input()

i = j = 0
so_far = 0
m = float('inf')

while i < n and a[i] == '0':
    i += 1

while j < n:
    if a[j] == '1':
        so_far += 1
    if so_far >= k:
        m = min(m, j - i + 1)
        j += 1
        i += 1
        while a[i] != '1' and i <= j:
            i += 1
        so_far -= 1
    elif so_far < k:
        j += 1

print(m)
# Check with 5
# 0 1 2 3 4 5 6 7 8 9 10 11 12 13
# 0 0 1 2 2 2 2 3 3 4  5  5  6  7
# 0 0 1 1 0 0 0 1 0 1  1  0  1  1

# Check with 3
# 00111000101010101
