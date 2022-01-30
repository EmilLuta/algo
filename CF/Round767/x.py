from random import randint

N = 2 * 10 ** 5
with open('test.txt', 'w+') as f:
    f.write(f"1\n{N}\n")
    for i in range(N):
        f.write(f"{randint(0, 3)} ")
    f.write("\n")
