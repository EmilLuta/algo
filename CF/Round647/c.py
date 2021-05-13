t = int(input())
x = {}
for i in range(61):
    x[2 ** i] = 2 ** (i + 1) - 1
out = ''
while t > 0:
    t -= 1
    n = int(input())
    answer = 0
    powers = sorted(x.keys())
    while n != 0:
        for i in range(len(powers)):
            if powers[i] > n:
                n -= powers[i - 1]
                answer += x[powers[i - 1]]
                break
    out += f'{answer}\n'
print(out)








# d = {0: 0}
# d1 = {0: 0}
# def diff(a, b):
#     a = bin(a).replace('0b', '')
#     b = bin(b).replace('0b', '')
#     a = '0' * (len(b) - len(a)) + a
#     answer = 0
#     for i in range(len(a)):
#         if a[i] != b[i]:
#             answer += 1
#     return answer

# for i in range(1, n + 1):
#     d1[i] = diff(i - 1, i)
#     d[i] = d[i - 1] + d1[i]
# x = len(bin(n).replace('0b', ''))
# for i in range(1, n + 1):
#     print(f'{i}: {(x - (len(bin(i)) - 2)) * "0" + bin(i).replace("0b", "")} - {d1[i]} + {d[i - 1]} = {d[i]}')

# print(max(d1.values()))

# x = {}
# for i in range(61):
#     x[2 ** i] = 2 ** (i + 1) - 1
# import code
# code.interact(local=dict(globals(), **locals()))
