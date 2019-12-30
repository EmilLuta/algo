n, m, r = [int(i) for i in input().split(' ')]
s = [int(i) for i in input().split(' ')]
b = [int(i) for i in input().split(' ')]
s_m = min(s)
b_m = max(b)
print(max(r, r // s_m * b_m + r % s_m))
