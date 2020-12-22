k = int(input())
a, b = [int(i) for i in input().split(' ')]
for i in range(a, b + 1):
    if i % k == 0:
        print('OK')
        break
else:
    print('NG')
