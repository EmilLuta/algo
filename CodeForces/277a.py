def go():
    n, m  = [int(i) for i in input().split(' ')]
    persons = []
    components = 0
    for i in range(n):
        data = [int(i) for i in input().split(' ')]
        if data[0] == 0:
            components += 1
        persons.append(set(data[1:]))
    visited = set()
    found = False
    for i in range(n):
        if i in visited:
            continue
        current_component = set()
        visited.add(i)
        for l in persons[i]:
            current_component.add(l)
        for j in range(i + 1, n):
            if j in visited:
                continue
            if persons[j].intersection(current_component):
                for l in persons[j]:
                    current_component.add(l)
                visited.add(j)
        for j in range(n - 1, i, -1):
            if j in visited:
                continue
            if persons[j].intersection(current_component):
                for l in persons[j]:
                    current_component.add(l)
                visited.add(j)
        if current_component:
            found = True
            components += 1
    if not found:
        components += 1
    return components - 1

print(go())
