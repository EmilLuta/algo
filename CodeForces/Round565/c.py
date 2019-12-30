from collections import defaultdict

def go():
    n = int(input())
    keys = [4, 8, 15, 16, 23, 42]
    keep = defaultdict(list)
    for i, e in enumerate(input().split(' ')):
        keep[int(e)].append(i)
    for k in keys:
        keep[k].reverse()
    to_remove = 0
    current = []
    index = 0
    while True:
        if len(current) == 6:
            for i in range(5):
                while current[i] > current[i + 1]:
                    if len(keep[keys[i + 1]]) > 0:
                        current[i + 1] = keep[keys[i + 1]].pop()
                        to_remove += 1
                    else:
                        break
            s_current = sorted(current)
            if s_current == current:
                current = []
                index = 0
            else:
                break
        if len(keep[keys[index]]) > 0:
            current.append(keep[keys[index]].pop())
            index += 1
        else:
            break
    return len(current) + sum(len(i) for i in keep.values()) + to_remove

print(go())
