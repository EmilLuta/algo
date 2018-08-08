def go():
    n = int(input())
    a = [i for i in input()]
    b = [i for i in input()]
    total = 0
    i_o = [0] * n
    i_i = [0] * n
    o_i = [0] * n
    o_o = [0] * n
    if a[n - 1] == '0' and b[n - 1] == '0':
        o_o[n - 1] += 1
    elif a[n - 1] == '1' and b[n - 1] == '1':
        i_i[n - 1] += 1
    elif a[n - 1] == '0' and b[n - 1] == '1':
        o_i[n - 1] += 1
    elif a[n - 1] == '1' and b[n - 1] == '0':
        i_o[n - 1] += 1

    for i in range(n - 2, -1, -1):
        o_o[i] += o_o[i + 1]
        i_i[i] += i_i[i + 1]
        i_o[i] += i_o[i + 1]
        o_i[i] += o_i[i + 1]
        if a[i] == '0' and b[i] == '0':
            o_o[i] += 1
        elif a[i] == '1' and b[i] == '1':
            i_i[i] += 1
        elif a[i] == '0' and b[i] == '1':
            o_i[i] += 1
        elif a[i] == '1' and b[i] == '0':
            i_o[i] += 1

    for i in range(n - 1):
        if a[i] == '0' and b[i] == '1':
            total += i_o[i + 1]
        elif a[i] == '0' and b[i] == '0':
            total += i_i[i + 1]
            total += i_o[i + 1]
        elif a[i] == '1' and b[i] == '1':
            total += o_o[i + 1]
        elif a[i] == '1' and b[i] == '0':
            total += o_o[i + 1]
            total += o_i[i + 1]
    return total

print(go())
