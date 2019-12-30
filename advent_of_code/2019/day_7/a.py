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

def go():
    data = get_data()
    n = len(data)
    i = 0
    while i < n:
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
            inp = int(input())
            data[values[0]] = inp
            i += 2
        elif operation_and_modes[0] == 4:
            values = get_values(data, operation_and_modes, i, n, 1)
            print(data[values[0]])
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
            print('Halted')
            return
        else:
            print(operation_and_modes[0])
            print('Shit hit the fan')
            return

go()
