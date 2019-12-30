from math import sqrt

n = int(input())

MAX_X = 500000
answer = [0] * (MAX_X + 1)

for i in range(1, MAX_X + 1):
    for j in range(i, MAX_X + 1, i): # O(N / i)
        answer[j] += i

# N / 1 + N / 2 + N / 3 + N / 4 + ... = N*log(N)

for i in range(n):
    number = int(input())
    print(answer[number] - number)
