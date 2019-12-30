""" Homework
1) Check if there is a quadruple such that:
(i, j, k, z): i < j < k < z and a[i] + a[j] = a[k] + a[z]
N <= 2000
2) Check if there is a quadruple such that:
(i, j, k, z): i < j < k < z and a[i] + a[k] = a[j] + a[z]
N <= 2000
3) Check if there is a quadruple such that:
(i, j, k, z): i < j < k < z and a[i] * a[k] = a[j] * a[z], https://community.topcoder.com/stat?c=problem_statement&pm=13951
N <= 2000
4) Find the maximum side of a cross of 1's in a matrix, N <= 2000. Think about a harder version: https://codeforces.com/problemset/problem/677/E; Don't care about the big number part.
"""

#####
# 1 #
#####

# a = [int(i) for i in input().split(' ')]

# def exists(a):
#     n = len(a)
#     d = {}
#     for i in range(n):
#         for j in range(i + 1, n):
#             s = a[i] + a[j]
#             if s not in d:
#                 d[s] = j

#     for z in range(n - 1, -1, -1):
#         for k in range(z - 1, -1, -1):
#             s = a[z] + a[k]
#             if s in d and d[s] < k:
#                 return True
#     return False

# print(exists(a))

#####
# 2 #
#####

# a = [int(i) for i in input().split(' ')]

# def exists(a):
#     n = len(a)
#     d = {}
#     for i in range(n):
#         for j in range(i + 1, n):
#             s = a[i] - a[j]
#             if s not in d:
#                 d[s] = j

#     for z in range(n - 1, -1, -1):
#         for k in range(z - 1, -1, -1):
#             s = a[z] - a[k]
#             if s in d and d[s] < k:
#                 return True
#     return False

# print(exists(a))

#####
# 3 #
#####

from math import gcd

a = [int(i) for i in input().split(' ')]
n = len(a)
d = {}
count = 0

for i in range(n):
    for j in range(i + 1, n):
        g = gcd(a[i], a[j])
        a_i = a[i] // g
        a_j = a[j] // g
        d.setdefault((a_i, a_j), [])
        d[(a_i, a_j)].append(j)

for k in range(n):
    for z in range(k + 1, n):
        g = gcd(a[k], a[z])
        a_k = a[k] // g
        a_l = a[z] // g
        division = (a_l, a_k)
        if division in d:
            for position in d[division]:
                if position < k:
                    count += 1
print(count)

#####
# 4 #
#####



n = int(input())
a = []
k = []

directions = ['left', 'right', 'up', 'down']

def process_row(i):
    j = 0
    while j < n:
        start = j
        while j < n and a[i][j] == 1:
            j += 1
        for x in range(start, j):
            value = x - start
            k[i][x]['left'] = value
            k[i][x]['right'] = j - x - 1
        j += 1

def process_column(j):
    i = 0
    while i < n:
        start = i
        while i < n and a[i][j] == 1:
            i += 1
        for x in range(start, i):
            value = x - start
            k[x][j]['up'] = value
            k[x][j]['down'] = i - x - 1
        i += 1

for i in range(n):
    a.append([int(i) for i in input().split(' ')])
    k.append([])
    for j in range(n):
        k[i].append({'left': 0, 'right': 0, 'up': 0, 'down': 0})

for i in range(n):
    process_row(i)
    process_column(i)

m = 0
for i in range(n):
    for j in range(n):
        m = max(m, min(k[i][j].values()))
print(m)
