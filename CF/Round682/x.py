a = 29
b = 98
x = 80
i = 0
j = 1
while a * i - b * j != x:
    if a * i - b * j < x:
        i += 1
    else:
        j += 1
print(i, j)
