from math import cos, pi, sin, sqrt

t = int(input())
out = ''
while t > 0:
    t -= 1
    n = int(input())
    angle = pi // (2 * n)
    answer = 1
    x = prev_x = 0
    y = prev_y = 0
    my_angle = 0
    to_go = n
    if n % 4 == 0:
        to_go -= 1
    answer = 0
    for i in range(n - 1):
        # angle += angle
        x = x + cos(angle)
        y = y + sin(angle)
    print(sqrt((x) ** 2 + (y) ** 2)
)
