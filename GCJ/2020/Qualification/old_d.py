t, b = [int(i) for i in input().split(' ')]
fff = open('dump.txt', 'w+')
for tc in range(1, t + 1):
    fff.write(f'Test Case = {tc}\n')
    a = [''] * b
    for i in range(5):
        print(i + 1)
        a[i] = input()
        print(b - i)
        a[b - i - 1] = input()
    found = 10
    while found < b:
        same = None
        diff = None
        for i in range(b // 2):
            if a[i] == a[b - i - 1] and a[i] != '':
                same = i
            elif a[i] != a[b - i - 1] and a[i] != '' and a[b - i - 1] != '':
                diff = i
        # import code
        # code.interact(local=dict(globals(), **locals()))
        used = 0
        sec = a[:]
        if same is not None:
            print(same + 1)
            x = input()
            used += 1
            if x != a[same]:
                for i in range(b // 2):
                    if a[i] == a[b - i - 1]:
                        sec[i] = '1' if a[i] == '0' else '0'
                        sec[b - i - 1] = '1' if a[b - i - 1] == '0' else '0'
        if diff is not None:
            print(diff + 1)
            x = input()
            used += 1
            if x != a[diff]:
                for i in range(b // 2):
                    if a[i] != a[b - i - 1]:
                        sec[i] = '1' if a[i] == '0' else '0'
                        sec[b - i - 1] = '1' if a[b - i - 1] == '0' else '0'
        a = sec
        # import code
        # code.interact(local=dict(globals(), **locals()))
        start = found // 2
        end = found // 2 + min((10 - used) // 2, (b - found) // 2)
        fff.write(f'found = {found}, used = {used}, going from {start} to {end}, covering ranges: {start} -> {end} and {b - end} -> {b - start}\n')
        for i in range(start, end):
            print(i + 1)
            a[i] = input()
            print(b - i)
            a[b - i - 1] = input()
            found += 2
            if found == b:
                break
        if found == b:
            break
        if used % 2 == 1:
            print(1)
            input()
    print(''.join(a))
    if input() != 'Y':
        exit(0)
