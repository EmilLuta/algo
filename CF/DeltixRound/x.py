a = 2
b = 9

def solve(x, y, ops):
    if x == -a and y == -b:
        print(x, y, ops)
        return
    if len(ops) == 5:
        return
    solve(x + y, y, ops[:] + ['+'])
    solve(x, y - x, ops[:] + ['-'])

solve(a, b, [])
