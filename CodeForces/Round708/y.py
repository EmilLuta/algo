n = int(input())

for i in range(1, 1000):
    left = n - i
    if left % 2 == 0:
        x = left // 2
        if x % i == 0:
            print(i, x, x)
            break
