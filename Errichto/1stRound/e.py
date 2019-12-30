# t = int(input())
# for _ in range(t):
#     n = int(input())
#     print('1 {} 1 {}'.format(n - 1, ' '.join(str(i) for i in range(2, n + 1))))
#     aim = int(input())
#     start = 2
#     end = n
#     while start != end:
#         mid = (start + end + 1) // 2
#         a = [i for i in range(start, mid)]
#         b = [i for i in range(mid, end + 1)]
#         print('1 {} 1 {}'.format(len(a), ' '.join(str(i) for i in a)))
#         answer = int(input())
#         if answer == aim:
#             end = mid
#         else:
#             start = mid
#     a = [i for i in range(1, n) if i != start]
#     print('1 {} {} {}'.format(len(a), start, ' '.join(str(i) for i in a)))
#     print('-1 {}'.format(input()))

import bisect


def bs(x):
    start = 2
    end = x
    while start < end:
        mid = (start + end) // 2
        print('Is it here? {} - {}'.format(start, mid)) # mid + 1
        print('If no, here? {} - {}'.format(mid + 1, end))
        answer = int(input())
        if answer == 1:
            end = mid
        else:
            start = mid + 1


# 43
bs(2)