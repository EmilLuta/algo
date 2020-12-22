with open('d.out', 'w+') as f:
    o = ''
    for i in range(1991):
        o += f'{i} '
    f.write(o.strip())
