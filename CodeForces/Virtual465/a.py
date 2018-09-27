def go():
    n = int(input())
    total = 0
    for i in range(1, n // 2 + 1):
        if (n - i) % i == 0:
            total += 1
    return total

print(go())
