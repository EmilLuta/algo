# 6) Given a sequence of positive integers and an integer K, cout the number of segments/intervals with the sum of elements at least K.
# answer = 0
# for i range(n):
#     for j in range(i, n):
#         sum = a[i] + a[i+1] + ... + a[j]
#         if sum >= K:
#             ++answer
# print(answer)

n, k = [int(i) for i in input().split(' ')]
a = [int(i) for i in input().split(' ')]

i = j = 0
sum_so_far = 0
answer = 0
while j < n:
    sum_so_far += a[j]
    if sum_so_far == k:
        answer += n - j
        sum_so_far -= a[i]
        i += 1
        j += 1
    elif sum_so_far < k:
        j += 1
    else:
        while sum_so_far >= k and i < n:
            answer += n - j
            sum_so_far -= a[i]
            i += 1
        j += 1
print("{} segments with sum at least {}".format(answer, k))
