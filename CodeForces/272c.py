def go():
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    m = int(input())
    o = ''
    for i in range(m):
        w, h = [int(i) for i in input().split(' ')]
        m = max(a[0], a[w - 1])
        a[0] = m + h
        o += '{}\n'.format(m)
    return o
print(go())
#0000
#0000
#0000
#   ##
#0  ##
#000##
#  ###
#0####
######


#1
#3
#4
#6

