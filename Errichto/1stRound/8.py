# Given a sequence of positive integers and an integer K, find the shortest segment/interval with the sum of elements at least K.

n, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

i = j = 0
sum_so_far = 0
i_m = float('-inf')
j_m = float('inf')

while j < n:
    sum_so_far += a[j]
    if sum_so_far == k:
        if j - i < j_m - i_m:
            j_m = j
            i_m = i
        j += 1
    elif sum_so_far < k:
        j += 1
    else:
        while sum_so_far > k and i <= j:
            sum_so_far -= a[i]
            i += 1
        sum_so_far -= a[j]

print("Interval {} - {} is shortest segment with sum {}".format(i_m, j_m, k))
