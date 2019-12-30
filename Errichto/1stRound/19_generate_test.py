with open('19_4_4_input.txt', 'w+') as f:
    n = 400
    f.write("{}\n".format(n))
    s = ""
    for j in range(n):
        s += '1 '
    s = s [:-1]
    s += '\n'
    for i in range(n):
        f.write(s)
