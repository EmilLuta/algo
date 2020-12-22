# v1

# def bin_search(a, val):
#     low = 0
#     high = len(a)
#     while low <= high:
#         mid = (high + low) // 2
#         curr = a[mid]
#         if curr == val:
#             return mid
#         elif curr < val:
#             low = mid + 1
#         else:
#             high = mid - 1
#     return None

# n, q = [int(i) for i in input().split(' ')]
# names = [i for i in sorted(input().split(' '))]
# scores = [0] * n

# for _ in range(q):
#     inp = [i for i in input().split(' ')]
#     name = inp[0]
#     value = int(inp[1])
#     index = bin_search(names, name)
#     scores[index] += value

# max_name = ''
# max_value = 0
# for i in range(n):
#     if max_value <= scores[i]:
#         max_name = names[i]
#         max_value = scores[i]
# print(max_name)

# v2

# def bin_search(a, val):
#     low = 0
#     high = len(a)
#     while low <= high:
#         mid = (high + low) // 2
#         curr = a[mid][0]
#         if curr == val:
#             return mid
#         elif curr < val:
#             low = mid + 1
#         else:
#             high = mid - 1
#     return None

# n, q = [int(i) for i in input().split(' ')]
# names_raw = [i for i in input().split(' ')]
# names = []
# for i in range(n):
#     names.append((names_raw[i], i))
# names.sort()
# scores = [0] * n

# for _ in range(q):
#     inp = [i for i in input().split(' ')]
#     name = inp[0]
#     value = int(inp[1])
#     index = bin_search(names, name)
#     scores[index] += value

# max_name = ''
# max_value = 0
# for i in range(n):
#     if max_value <= scores[i]:
#         max_name = names[i]
#         max_value = scores[i]
# print(max_name)

# v3

# def bin_search(a, val):
#     low = 0
#     high = len(a)
#     while low <= high:
#         mid = (high + low) // 2
#         curr = a[mid]
#         if curr == val:
#             return mid
#         elif curr < val:
#             low = mid + 1
#         else:
#             high = mid - 1
#     return None


# q = int(input())
# queries = []
# duplicate_names = []
# for _ in range(q):
#     inp = [i for i in input().split(' ')]
#     name = inp[0]
#     value = int(inp[1])
#     queries.append((name, value))
#     duplicate_names.append(name)
# names = []
# duplicate_names.sort()
# nn = len(duplicate_names)
# i = 0
# while i < nn:
#     j = i + 1
#     names.append(duplicate_names[i])
#     while j < nn and duplicate_names[j] == duplicate_names[i]:
#         j += 1
#     i = j
# n = len(names)
# names.sort()
# scores = [0] * n

# for name, value in queries:
#     index = bin_search(names, name)
#     scores[index] += value

# max_name = ''
# max_value = 0
# for i in range(n):
#     if max_value <= scores[i]:
#         max_name = names[i]
#         max_value = scores[i]
# print(max_name)
