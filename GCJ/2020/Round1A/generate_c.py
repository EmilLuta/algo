from random import randint

N = 10

a = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        a[i][j] = randint(1, N)
print(1)
print(f'{N} {N}')
for i in range(N):
    print(' '.join(str(x) for x in a[i]))
