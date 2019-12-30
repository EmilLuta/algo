n = int(input())
a = [i for i in input()]
z = o = 0
for i in range(n):
    if a[i] == '0':
        z += 1
    else:
        o += 1
if z != o:
    print('{}\n{}'.format(1, ''.join(a)))
    exit()
z_l = o_l = 0
for i in range(n):
    if a[i] == '0':
        z_l += 1
        z -= 1
    else:
        o_l += 1
        o -= 1
    if z_l != o_l and z != o:
        print('2\n{} {}'.format(''.join(a[:i + 1]), ''.join(a[i + 1:])))
        exit()
# z_l = o_l = 0
# z_r, o_r = z, o
# if a[0] == '0':
#     z_r -= 1
# else:
#     o_r -= 1
# for i in range(2, n):
#     if a[i] == '0':
#         z_l += 1
#         z_r -= 1
#     else:
#         o_l += 1
#         o_r -= 1
#     if z_l != o_l and z_r != o_r:
#         print('3\n{} {} {}'.format(a[0], ''.join(a[1:i]), ''.join(a[i:])))
#         exit()

