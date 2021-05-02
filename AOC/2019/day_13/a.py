from collections import defaultdict
from time import sleep

def get_data():
    with open('input.txt', 'r') as f:
        inp = f.read()
    data = defaultdict(int)
    for i, val in enumerate(inp.split(',')):
        data[i] = int(val)
    return data

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

def get_values(data, operation_and_modes, index, relative_base, how_many):
    values = [0] * how_many
    for i in range(1, how_many + 1):
        if operation_and_modes[i] == 2:
            values[i - 1] = data[index + i] + relative_base
        elif operation_and_modes[i] == 1:
            values[i - 1] = index + i
        elif operation_and_modes[i] == 0:
            values[i - 1] = data[index + i]
    return values

def go():
    data = get_data()
    n = len(data)
    i = 0
    output = []
    relative_base = 0
    while i < n:
        operation_and_modes = get_operation_and_modes(data, i)
        if operation_and_modes[0] == 1:
            values = get_values(data, operation_and_modes, i, relative_base, 3)
            data[values[2]] = data[values[1]] + data[values[0]]
            i += 4
        elif operation_and_modes[0] == 2:
            values = get_values(data, operation_and_modes, i, relative_base, 3)
            data[values[2]] = data[values[1]] * data[values[0]]
            i += 4
        elif operation_and_modes[0] == 3:
            values = get_values(data, operation_and_modes, i, relative_base, 1)
            inp = int(input())
            data[values[0]] = inp
            i += 2
        elif operation_and_modes[0] == 4:
            values = get_values(data, operation_and_modes, i, relative_base, 1)

            output.append(data[values[0]])
            i += 2
        elif operation_and_modes[0] == 5:
            values = get_values(data, operation_and_modes, i, relative_base, 2)
            if data[values[0]] != 0:
                i = data[values[1]]
            else:
                i += 3
        elif operation_and_modes[0] == 6:
            values = get_values(data, operation_and_modes, i, relative_base, 2)
            if data[values[0]] == 0:
                i = data[values[1]]
            else:
                i += 3
        elif operation_and_modes[0] == 7:
            values = get_values(data, operation_and_modes, i, relative_base, 3)
            if data[values[0]] < data[values[1]]:
                data[values[2]] = 1
            else:
                data[values[2]] = 0
            i += 4
        elif operation_and_modes[0] == 8:
            values = get_values(data, operation_and_modes, i, relative_base, 3)
            if data[values[0]] == data[values[1]]:
                data[values[2]] = 1
            else:
                data[values[2]] = 0
            i += 4
        elif operation_and_modes[0] == 9:
            values = get_values(data, operation_and_modes, i, relative_base, 1)
            relative_base += data[values[0]]
            i += 2
        elif operation_and_modes[0] == 99:
            print('Halted')
            return output
        else:
            print('Shit hit the fan')
            return


def main():
    options = go()
    out = 0
    for i in range(2, len(options), 3):
        if options[i] == 2:
            out += 1
    print(out)
main()
