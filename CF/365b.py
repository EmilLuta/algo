def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    if n == 1:
        return 1
    elif n == 2:
        return 2
    i = 2
    global_max = 2
    current_max = 2
    while i < n:
        if a[i - 1] + a[i - 2] == a[i]:
            current_max += 1
        else:
            if current_max > global_max:
                global_max = current_max
            current_max = 2
        i += 1
    if global_max < current_max:
        return current_max
    return global_max

print(go())
