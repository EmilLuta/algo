def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    m = int(input())
    b = [int(i) for i in input().split(' ')]
    i = 0
    so_far_i = 0
    j = 0
    so_far_j = 0
    while i < n and so_far_i < n and j < m and so_far_j < m:
        if a[i] == b[j]:
            i = so_far_i
            j = so_far_j
            i += 1
            j += 1
            so_far_i = i
            so_far_j = j
        else:
            if a[i] > b[j]:
                if so_far_j + 1 < m:
                    b[j] += b[so_far_j + 1]
                    so_far_j += 1
                    b[so_far_j] = None
                else:
                    break
            else:
                if so_far_i + 1 < n:
                    a[i] += a[so_far_i + 1]
                    so_far_i += 1
                    a[so_far_i] = None
                else:
                    break
    if sum([i for i in a if i is not None]) != sum([i for i in b if i is not None]):
        return -1
    return len([i for i in a if i is not None])

print(go())
