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

def run(data, i, relative_base, stdin):
    found = False
    stdout = []
    n = len(data)
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
            inp = stdin
            data[values[0]] = inp
            i += 2
        elif operation_and_modes[0] == 4:
            values = get_values(data, operation_and_modes, i, relative_base, 1)
            stdout.append(data[values[0]])
            i += 2
            if found:
                return data, i, relative_base, stdout
            else:
                found = True
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
            return data, i, relative_base, ['Halted']
        else:
            print('Shit hit the fan')
            return

# x = 0

# def run(data, i, relative_base, stdin):
#     global x
#     if x == 0 or x == 2 or x == 3 or x == 5 or x == 6:
#         out = [1, 0]
#     elif x == 1:
#         out = [0, 0]
#     elif x == 4:
#         out = [0, 1]
#     else:
#         out = ['Halted', 0]
#     x += 1
#     return data, i, relative_base, out

def go():
    data = get_data()
    i = 0
    relative_base = 0
    visited = set()
    robot_painting = {}
    robot = ['U', 0, 0]
    data, i, relative_base, stdout = run(data, i, relative_base, 1)
    c = 0
    while stdout[0] != 'Halted':
        if (robot[1], robot[2]) not in robot_painting:
            c += 1
        robot_painting[(robot[1], robot[2])] = stdout[0]
        if robot[0] == 'U':
            if stdout[1] == 0:
                robot[0] = 'L'
                robot[2] -= 1
            elif stdout[1] == 1:
                robot[0] = 'R'
                robot[2] += 1
            else:
                print('Wrong move?')
        elif robot[0] == 'D':
            if stdout[1] == 0:
                robot[0] = 'R'
                robot[2] += 1
            elif stdout[1] == 1:
                robot[0] = 'L'
                robot[2] -= 1
            else:
                print('Wrong move?')
        elif robot[0] == 'L':
            if stdout[1] == 0:
                robot[0] = 'D'
                robot[1] += 1
            elif stdout[1] == 1:
                robot[0] = 'U'
                robot[1] -= 1
            else:
                print('Wrong move?')
        elif robot[0] == 'R':
            if stdout[1] == 0:
                robot[0] = 'U'
                robot[1] -= 1
            elif stdout[1] == 1:
                robot[0] = 'D'
                robot[1] += 1
            else:
                print('Wrong move?')
        else:
            print('WTF?')
        stdin = 0
        if (robot[1], robot[2]) in robot_painting:
            stdin = robot_painting[(robot[1], robot[2])]
        data, i, relative_base, stdout = run(data, i, relative_base, stdin)
    print(c)
    s_x = float('inf')
    s_y = float('inf')
    b_x = float('-inf')
    b_y = float('-inf')
    counting = 0
    for key in robot_painting:
        print(key)
        if robot_painting[key] == 1:
            counting += 1
        s_x = min(s_x, key[1])
        s_y = min(s_y, key[0])
        b_x = max(b_x, key[1])
        b_y = max(b_y, key[0])
    print(s_x, b_x)
    print(s_y, b_y)
    print(counting)
    for y in range(s_y, b_y + 1):
        o = ''
        for x in range(s_x, b_x + 1):
            if (y, x) in robot_painting:
                if robot_painting[(y, x)] == 0:
                    o += ' '
                else:
                    o += '#'
            else:
                o += ' '
        print(o)
go()
