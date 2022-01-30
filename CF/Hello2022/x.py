from random import randint

M = 15

n = randint(6, 15)
with open("test.txt", "w+") as f:
    f.write(f"1\n{n}\n")
    for i in range(n):
        x = randint(1, M)
        y = randint(x, M)
        c = randint(1, M)
        f.write(f"{x} {y} {c}\n")

