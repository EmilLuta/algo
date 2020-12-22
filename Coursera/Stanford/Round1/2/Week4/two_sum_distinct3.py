from collections import defaultdict

def load_data():
    data = []
    with open('input.txt', 'r') as f:
        for line in f:
            data.append(int(line.strip()))
    return data

data = list(set(load_data()))
c = defaultdict(int)
c_uniq = defaultdict(int)

for i in range(len(data)):
    for j in range(i + 1, len(data)):

        x = data[i] + data[j]
        if x >= -10000 and x <= 10000:
            if data[i] != data[j]:
                c_uniq[x] += 1
            c[x] += 1
    if i % 1000 == 0:
        print(len(c))
        print(f'{i}/{len(data)}')

print(len(c))
import code
code.interact(local=dict(globals(), **locals()))
