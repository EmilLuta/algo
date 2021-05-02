from collections import defaultdict


def get_data():
    with open("input.txt", "r") as f:
        inp = f.read()
    data = defaultdict(int)
    for i, val in enumerate(inp.split(",")):
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
    out = ""
    data = get_data()
    n = len(data)
    i = 0
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

            # print(data[values[0]])
            out += chr(data[values[0]])
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
            print("Halted")
            return out
        else:
            print("Shit hit the fan")
            return


def draw(matrix):
    for y in range(len(matrix)):
        out = ""
        for x in range(len(matrix[0])):
            out += matrix[y][x]
        print(out)


def get_intersections(matrix):
    intersections = []
    m = len(matrix)
    n = len(matrix[0])
    for y in range(m):
        for x in range(n):
            if y > 0 and y < m - 1 and x > 0 and x < n - 1 and matrix[y][x] == '#':
                found = True
                for d in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if matrix[y + d[0]][x + d[1]] != "#":
                        found = False
                if found:
                    intersections.append((x, y))
    return intersections

def get_new_direction(direction, d):
    if direction == 'U':
        if d == (1, 0):
            return 'R', 'R'
        elif d == (-1, 0):
            return 'L', 'L'
    if direction == 'D':
        if d == (1, 0):
            return 'R', 'L'
        elif d == (-1, 0):
            return 'L', 'R'
    if direction == 'R':
        if d == (0, 1):
            return 'D', 'R'
        elif d == (0, -1):
            return 'U', 'L'
    if direction == 'L':
        if d == (0, 1):
            return 'D', 'L'
        elif d == (0, -1):
            return 'U', 'R'

def valid(matrix, new_pos):
    if new_pos[0] >= 0 and new_pos[0] < len(matrix[-1]) and new_pos[1] >= 0 and new_pos[1] < len(matrix):
        return True
    return False

def dfs(matrix, car_direction, direction, position, going_to, so_far, visited, output):
    draw(matrix)
    # import code
    # code.interact(local=dict(globals(), **locals()))
    # input()
    matrix[position[1]][position[0]] = 'X'
    new_pos = (position[0] + going_to[0], position[1] + going_to[1])
    if valid(matrix, new_pos) and (matrix[new_pos[1]][new_pos[0]] == '#' or matrix[new_pos[1]][new_pos[0]] == 'X'):
        dfs(matrix, car_direction, direction, new_pos, going_to, so_far + 1, visited, output)
        return
    for d in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        if d == going_to:
            continue
        x = (d[0] * -1, d[1] * -1)
        if x == going_to:
            continue
        new_pos = (position[0] + d[0], position[1] + d[1])
        if valid(matrix, new_pos) and (matrix[new_pos[1]][new_pos[0]] == '#' or matrix[new_pos[1]][new_pos[0]] == 'X'):
            output.append(f'{direction}{so_far}')
            so_far = 1
            car_direction, new_direction = get_new_direction(car_direction, d)
            dfs(matrix, car_direction, new_direction, new_pos, d, so_far, visited, output)
            return

def print_and_find_combination(out):
    seq = ' '.join(out)
    moves = seq.split()
    for a_e in range(2, 8):
        for b_s in range(a_e+1, len(moves)-3):
            for b_e in range(b_s+2, b_s+2+8):
                a = " ".join(moves[0:a_e])
                b = " ".join(moves[b_s:b_e])
                rem = seq.replace(a, '|').replace(b, '|')
                _,min_c = min((len(c.strip()),c.strip()) for c in rem.split('|') if len(c.strip()) > 0)
                rem = rem.replace(min_c, '').replace(' ', '').replace('|', '')
                if len(rem) == 0:
                    print("FOUND A=%s, B=%s, C=%s" % (a,b,min_c))

def main():
    out = go().strip()
    matrix = [[]]
    for i in out:
        if i == '\n':
            matrix.append([])
        else:
            if i == '^':
                start = (len(matrix[-1]), len(matrix) - 1)
            matrix[-1].append(i)
    draw(matrix)
    intersections = set(get_intersections(matrix))
    out = 0
    for intersection in intersections:
        out += intersection[0] * intersection[1]
    # import code
    # code.interact(local=dict(globals(), **locals()))
    direction = 'L'
    so_far = 0
    visited = set([start])
    output = []
    going_to = (-1, 0)
    dfs(matrix, 'L', direction, start, going_to, so_far, visited, output)
    print_and_find_combination(output)
    print(output)

main()
