t = int(input())

def fill()

for tc in range(1, t + 1):
    n, k = [int(i) for i in input().split(' ')]
    matrix = [[0] * n for _ in n]
    for i in range(n):
