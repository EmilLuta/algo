
n = int(input())
w = input()
cache = []
for i in range(n):
    cache.append([0] * 26)
for i in range(n):
    cache[i] = cache[i - 1][:]
    cache[i][ord(w[i]) - ord('a')] += 1

def found(current, index):
    for i in range(26):
        if current[i] > cache[index][i]:
            return False
    return True

o = ''

m = int(input())
for _ in range(m):
    current = [0] * 26
    name = input()
    for letter in name:
        current[ord(letter) - ord('a')] += 1
    start = len(name) - 1
    while start < n:
        if found(current, start):
            o += str(start + 1) + '\n'
            break
        start += 1
print(o)


