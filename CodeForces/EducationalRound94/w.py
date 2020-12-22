tc = int(input("Which test case? "))

with open('x.txt', 'r') as f:
    i = 0
    out = ''
    while i < tc:
        out = f.readline()
        out += f.readline()
        out += f.readline()
        i += 1
    print(out)
