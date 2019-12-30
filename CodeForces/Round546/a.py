def go():
    n = int(input())
    books = []
    for i in range(n):
        books.append([int(i) for i in input().split(' ')][1])
    k = int(input())
    read = 0
    for i in range(n):
        if books[i] >= k:
            return n - read
        read += 1

print(go())
