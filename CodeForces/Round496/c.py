def go():
    input()
    from collections import Counter
    c = Counter([int(i) for i in input().split(' ')])
    powers_of_two = [1 << i for i in range(31)]
    total = 0
    for key in c:
        for power in powers_of_two:
            if power - key > 0 and power - key in c and (c[key] >= 2 or power - key != key):
                break
        else:
            total += c[key]
    return total
print(go())
