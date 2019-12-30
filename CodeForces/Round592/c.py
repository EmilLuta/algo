n, p, w, d = [int(i) for i in input().split(' ')]

wins = p // w
runs = d + 5
while runs >= 0 and wins >= 0:
    points_to_cover = p - w * wins
    if points_to_cover % d == 0:
        draws = points_to_cover // d
        if wins + draws > n:
            print(-1)
            exit(0)
        print(f'{wins} {draws} {n - wins - draws}')
        exit(0)
    wins -= 1
    runs -= 1
print(-1)
