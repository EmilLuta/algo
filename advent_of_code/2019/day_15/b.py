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
            i += 2
            return data.copy(), i, relative_base, data[values[0]]
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
            return data, i, relative_base, 'HALTED'
        else:
            print('Shit hit the fan')
            return

def draw(graph):
    min_x = min_y = float('inf')
    max_x = max_y = float('-inf')
    for point in graph:
        min_x = min(min_x, point[0])
        max_x = max(max_x, point[0])
        min_y = min(min_y, point[1])
        max_y = max(max_y, point[1])
    for y in range(min_y, max_y + 1):
        out = ''
        for x in range(min_x, max_x + 1):
            if (x == 0 and y == 0):
                out += 'S'
            elif (x, y) in graph:
                out += graph[(x, y)]
            else:
                out += '#'
        print(out)

directions = {
    1: (0, -1),
    2: (0, 1),
    3: (-1, 0),
    4: (1, 0),
}

end_point = None

def explore_grid_dfs(graph, point, direction, data, i, relative_base):
    global end_point
    data, i, relative_base, stdout = run(data.copy(), i, relative_base, direction)
    if stdout == 0:
        graph[point] = '#'
        return
    elif stdout == 1:
        graph[point] = '.'
    elif stdout == 2:
        graph[point] = 'O'
        end_point = point
    for direction in directions:
        new_point = (point[0] + directions[direction][0], point[1] + directions[direction][1])
        if new_point not in graph:
            explore_grid_dfs(graph, new_point, direction, data, i, relative_base)

def bfs(graph):
    global end_point
    print(end_point)
    queue = [(-12, 18)]
    parents = {(-12, 18): 0}
    i = 0
    n = 1
    while i < n:
        point = queue[i]
        for direction in directions.values():
            new_point = (point[0] + direction[0], point[1] + direction[1])
            if new_point not in parents and graph[new_point] != '#':
                queue.append(new_point)
                parents[new_point] = parents[point] + 1
                n += 1
        i += 1
    print(max(parents.values()))


def go():
    data = get_data()
    i = 0
    relative_base = 0
    graph = {(0, 0): 'S'}
    explore_grid_dfs(graph, (0, -1), 1, data, i, relative_base)
    explore_grid_dfs(graph, (0, 1), 2, data, i, relative_base)
    explore_grid_dfs(graph, (-1, 0), 3, data, i, relative_base)
    explore_grid_dfs(graph, (1, 0), 4, data, i, relative_base)

    draw(graph)
    bfs(graph)

go()
