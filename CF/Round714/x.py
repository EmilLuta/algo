a = [9]
for x in range(1, 201):
    for i in range(len(a) - 1, -1, -1):
        a[i] += 1
        if a[i] == 10:
            a[i] = 0
            a.insert(i, 1)
    print(f"after step {x}", len(a))
