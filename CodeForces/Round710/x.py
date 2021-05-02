with open('in.txt', 'w+') as f:
    f.write("1\n")
    f.write(str(2 * 10 ** 5) + "\n")
    for i in range(2 * 10 ** 5, 0, -1):
        f.write(str(i) + " ")
