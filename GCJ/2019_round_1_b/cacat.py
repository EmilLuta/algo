import random
with open('tests', 'w+') as f:
    f.write("100\n")
    for i in range(100):
        o = ""
        o2 = ""
        for j in range(1,101):
            o += str(random.randint(1, 100000)) + " "
        o = o[:-1]
        f.write("100 0\n")
        f.write(o + "\n")
        f.write(o + "\n")


