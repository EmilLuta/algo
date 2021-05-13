n = int(input())
for i in range(n):
    print(sum([int(i) for i in input().split(' ')]) // 2)
