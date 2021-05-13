def go():
    n = int(input())
    for i in [4, 7, 47, 74, 477, 744]:
        if n % i == 0:
            return 'YES'
    return 'NO'

print(go())
