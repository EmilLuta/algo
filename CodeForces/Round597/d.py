n = int(input())
unvisited = {i for i in range(n)}
visited = set()
lights = []
connections = []
cities = []
output = 0
for _ in range(n):
    x, y = [int(i) for i in input().split(' ')]
    cities.append((x, y))
c = [int(i) for i in input().split(' ')]
k = [int(i) for i in input().split(' ')]

min_index = 0
min_value = float('inf')
for i in range(n):
    if c[i] < min_value:
        min_value = c[i]
        min_index = i

visited.add(min_index)
unvisited.remove(min_index)
lights.append(min_index)
output += min_value

for u in unvisited:
    min_index = 0
    min_value = float('inf')
    light = False
    for v in visited:
        wire_cost = (k[v] + k[u]) * (abs(cities[v][0] - cities[u][0]) + abs(cities[v][1] - cities[u][1]))
        if c[u] < min_value:
            min_value = c[u]
            min_index = u
            light = True
        if wire_cost < min_value:
            min_value = wire_cost
            min_index = v
            light = False
    visited.add(u)
    output += min_value
    if light:
        lights.append(u)
    else:
        connections.append((min_index, u))
lights = [i + 1 for i in lights]
o = str(output) + "\n"
o += str(len(lights)) + "\n"
for i in lights:
    o += str(i) + " "
o += "\n"
o += str(len(connections)) + "\n"
for connection in connections:
    o += f'{connection[0] + 1} {connection[1] + 1}\n'
print(o)
