from random import randint

with open('input.txt', 'w+') as f:
    f.write("1\n")
    f.write("100\n")
    for i in range(100):
        f.write(f"{randint(1, 10 ** 9)}")
        f.write(" ")
    f.write("\n")
