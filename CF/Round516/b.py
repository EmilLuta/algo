def go():
    t = int(input())
    for i in range(t):
        a = int(input())
        print(2 ** bin(a).count('1'))
go()
