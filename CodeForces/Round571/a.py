def go():
    a = [int(i) for i in input().split(' ')]
    if a[0] <= a[1] and a[0] <= a[2]:
        return 'Yes'
    return 'No'

print(go())
