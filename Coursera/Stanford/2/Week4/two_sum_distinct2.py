def load_data():
    data = []
    with open('input.txt', 'r') as f:
        for line in f:
            data.append(int(line.strip()))
    return data

data = sorted(list(set(load_data())))
sums = set()

i = 0
j = len(data) - 1
k = 0
while i < j:
    x = data[j] + data[i]
    if x >= -10000 and x <= 10000:
        sums.add(x)
    if data[j - 1] != data[i]:
        x = data[j - 1] + data[i]
        if x >= -10000 and x <= 10000:
            sums.add(x)
    if data[j] != data[i + 1]:
        x = data[j] + data[i + 1]
        if x >= -10000 and x <= 10000:
            sums.add(x)
    i += 1
    j -= 1
    k += 2
    if k % 10000 == 0:
        print(len(sums))
        print(f'{k}/{len(data)}')
print(len(sums))
