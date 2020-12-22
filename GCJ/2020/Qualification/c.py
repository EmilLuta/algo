t = int(input())

START = 1
END = 0

out = ''

for tc in range(1, t + 1):
    n = int(input())
    events = []
    for i in range(n):
        e = [int(x) for x in input().split(' ')]
        events.append((e[0], START, i))
        events.append((e[1], END, i))
    events.sort()
    schedule = {}
    keep = {}
    impossible = False
    free = set('CJ')
    for i in range(len(events)):
        e_time, e_type, e_id = events[i]
        if e_type == START:
            if len(free) == 0:
                impossible = True
                break
            person = free.pop()
            schedule[e_id] = person
            keep[e_id] = person
        else:
            person = schedule.pop(e_id)
            free.add(person)
    if impossible:
        out += 'Case #{}: IMPOSSIBLE\n'.format(tc)
        continue
    out += 'Case #{}: {}\n'.format(tc, ''.join(keep[i] for i in range(n)))
print(out)
