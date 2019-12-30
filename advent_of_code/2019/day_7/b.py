def get_data():
    with open('input.txt', 'r') as f:
        inp = f.read()
    data = [int(i) for i in inp.split(',')]
    return data

def get_value(data, index, offset, n):
    if index + offset < n and data[index + offset] < n:
        return data[index + offset]
    return ValueError(f'Failed to get value at position {index + offset}, offset {offset}')

def get_operation_and_modes(data, i):
    output = [0] * 5
    x = data[i] // 100
    output[0] = data[i] % 100
    k = 1
    while x > 0:
        output[k] = x % 10
        x //= 10
        k += 1
    return output

def get_values(data, operation_and_modes, index, n, how_many):
    values = [0] * how_many
    for i in range(1, how_many + 1):
        if index + i < n:
            if operation_and_modes[i] == 1:
                values[i - 1] = index + i
            else:
                if data[index + i] < n:
                    values[i - 1] = data[index + i]
                else:
                    raise ValueError(f'Failed to get second level value at position {index + i}, offset {i}')
        else:
            raise ValueError(f'Failed to get first level value at position {index + i}, offset {i}')
    return values

def continue_thruster(data, i, stdin):
    n = len(data)
    x = 0
    while True:
        operation_and_modes = get_operation_and_modes(data, i)
        if operation_and_modes[0] == 1:
            values = get_values(data, operation_and_modes, i, n, 3)
            data[values[2]] = data[values[1]] + data[values[0]]
            i += 4
        elif operation_and_modes[0] == 2:
            values = get_values(data, operation_and_modes, i, n, 3)
            data[values[2]] = data[values[1]] * data[values[0]]
            i += 4
        elif operation_and_modes[0] == 3:
            values = get_values(data, operation_and_modes, i, n, 1)
            inp = stdin[x]
            x += 1
            data[values[0]] = inp
            i += 2
        elif operation_and_modes[0] == 4:
            values = get_values(data, operation_and_modes, i, n, 1)
            return data, i + 2, data[values[0]]
        elif operation_and_modes[0] == 5:
            values = get_values(data, operation_and_modes, i, n, 2)
            if data[values[0]] != 0:
                i = data[values[1]]
            else:
                i += 3
        elif operation_and_modes[0] == 6:
            values = get_values(data, operation_and_modes, i, n, 2)
            if data[values[0]] == 0:
                i = data[values[1]]
            else:
                i += 3
        elif operation_and_modes[0] == 7:
            values = get_values(data, operation_and_modes, i, n, 3)
            if data[values[0]] < data[values[1]]:
                data[values[2]] = 1
            else:
                data[values[2]] = 0
            i += 4
        elif operation_and_modes[0] == 8:
            values = get_values(data, operation_and_modes, i, n, 3)
            if data[values[0]] == data[values[1]]:
                data[values[2]] = 1
            else:
                data[values[2]] = 0
            i += 4
        elif operation_and_modes[0] == 99:
            # print('Halted')
            return data, i, 'Halted'
        else:
            print(operation_and_modes[0])
            print('Shit hit the fan')
            return

def go():
    data = get_data()
    n = len(data)
    maximum = float('-inf')
    for i in range(5, 10):
        for j in range(5, 10):
            if i == j:
                continue
            for k in range(5, 10):
                if k == i or k == j:
                    continue
                for l in range(5, 10):
                    if l == i or l == j or l == k:
                        continue
                    for m in range(5, 10):
                        if m == i or m == j or m == k or m == l:
                            continue

                        i1 = 0
                        i2 = 0
                        i3 = 0
                        i4 = 0
                        i5 = 0
                        data1 = data[:]
                        data2 = data[:]
                        data3 = data[:]
                        data4 = data[:]
                        data5 = data[:]
                        data1, i1, out1 = continue_thruster(data1, i1, [i, 0])
                        # print(f'A = {out1}')
                        data2, i2, out2 = continue_thruster(data2, i2, [j, out1])
                        # print(f'B = {out2}')
                        data3, i3, out3 = continue_thruster(data3, i3, [k, out2])
                        # print(f'C = {out3}')
                        data4, i4, out4 = continue_thruster(data4, i4, [l, out3])
                        # print(f'D = {out4}')
                        data5, i5, out5 = continue_thruster(data5, i5, [m, out4])
                        # print(f'E = {out5}')
                        good = out5
                        while out5 != 'Halted':
                            data1, i1, out1 = continue_thruster(data1, i1, [out5])
                            # print(f'A = {out1}')
                            data2, i2, out2 = continue_thruster(data2, i2, [out1])
                            # print(f'B = {out2}')
                            data3, i3, out3 = continue_thruster(data3, i3, [out2])
                            # print(f'C = {out3}')
                            data4, i4, out4 = continue_thruster(data4, i4, [out3])
                            # print(f'D = {out4}')
                            data5, i5, out5 = continue_thruster(data5, i5, [out4])
                            # print(f'E = {out5}')
                            if out5 != 'Halted':
                                good = out5
                        # print(f'Answer = {good}')
                        maximum = max(maximum, good)
                        print(f'Ran with i = {i}, j = {j}, k = {k}, l = {l}, m = {m} and got current = {good}, max = {maximum}')
    print(maximum)

go()
