start = 100
end = int(input())
c = 0
while start < end:
    start += int(start * 0.01)
    c += 1
print(c)
