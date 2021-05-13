# def bs(nums, target):
#     if len(nums) == 0:
#         return -1

#     left, right = 0, len(nums)
#     while left < right:
#         mid = (left + right) // 2
#         if nums[mid] == target:
#             return mid
#         elif nums[mid] < target:
#             left = mid + 1
#         else:
#             right = mid
#     return left - 1

def go():
    n, k = [int(i) for i in input().split(' ')]
    a = [int(i) for i in input().split(' ')]
    a.sort()
    keep = [a[0]]
    for i in range(1, n):
        keep.append(a[i] + keep[i - 1])
    r = keep[-1]
    c = 0
    while a:
        if k < a[-1]:
            a.pop()
            r = sum(a)
            keep.pop()
            n -= 1
        elif k == r:
            return c + n
        elif k > r:
            c += k // r * n
            k -= k // r * r
        else:
            for i in range(n):
                if k < a[i]:
                    return c
                k -= a[i]
                c += 1
    return c
print(go())

