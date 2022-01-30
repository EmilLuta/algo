from random import randint

n = 8

with open('test.txt', 'w+')  as f:
    f.write(f"{n}\n")
    for i in range(n * 2 - 1):
        for j in range(i + 1, n * 2):
            f.write(f"{randint(1, 100)} ")
        f.write("\n");
