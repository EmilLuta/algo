
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
    start = 0
    end = len(cache)
    while start < end:
        mid = (start + end) // 2
        if found(current, mid):
            end = mid
        else:
            start = mid + 1
    o += str(start + 1) + '\n'
print(o)


