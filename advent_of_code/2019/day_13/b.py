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

def draw(screen):
    min_x = min_y = float('inf')
    max_x = max_y = float('-inf')
    a = {}
    score = 0
    for i in range(0, len(screen)):
        if i % 3 == 0:
            x = screen[i]
            min_x = min(min_x, screen[i])
            max_x = max(max_x, screen[i])
        if i % 3 == 1:
            min_y = min(min_y, screen[i])
            max_y = max(max_y, screen[i])
            y = screen[i]
        if i % 3 == 2:
            if x == -1 and y == 0:
                score = screen[i]
                continue
            a[(y, x)] = screen[i]
    for y in range(min_y, max_y):
        s = ''
        for x in range(min_x, max_x):
            if (y, x) in a:
                if a[(y, x)] == 0:
                    s += ' '
                elif a[(y, x)] == 1:
                    s += 'X'
                elif a[(y, x)] == 2:
                    s += '#'
                elif a[(y, x)] == 3:
                    s += '-'
                elif a[(y, x)] == 4:
                    s += 'o'
                else:
                    s += '?'
        print(s)
    print(f'SCORE: {score}')

def go(game_data):
    data = get_data()
    n = len(data)
    i = move = 0
    output = []
    w = []
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
            draw(output)
            if len(game_data) > 0:
                inp = game_data[0]
                game_data.pop(0)
                # print(f'Used {inp} from game_data')
                # sleep(0.001)
                # sleep(0.1)
            else:
                inp = input()
                if inp == 'a':
                    inp = -1
                elif inp == 'd':
                    inp = 1
                else:
                    inp = 0
                w.append(inp)
            move += 1
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
            draw(output)
            print(f'Halted at {move}')
            return w
        else:
            print('Shit hit the fan')
            return


def main():
    game_data = []
    with open('game_data', 'r') as f:
        game_data = f.read().strip()
        game_data = game_data.split('\n')
        game_data = [int(x) for x in game_data if not x.startswith('===')]
    
    x = go(game_data)
    inp = input('Do you wanna write to file?')
    if inp == 'y':
        with open('x_data', 'w+') as f:
            f.write('\n'.join(str(i) for i in x))

main()
