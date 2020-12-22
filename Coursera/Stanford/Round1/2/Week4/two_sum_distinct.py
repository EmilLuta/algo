from collections import defaultdict

def load_data():
    data = []
    with open('input.txt', 'r') as f:
        for line in f:
            data.append(int(line.strip()))
    return data

data = load_data()
s_data = set(data)
s = defaultdict(int)

for index, i in enumerate(data):
    for j in range(-10000, 10001):
        if i - j in s_data and i - j != i:
            s[tuple(sorted([i, i - j]))] += 1
    if index % 1000 == 0:
        print(len(s))
        print(f'{index}/{len(data)}')

print(len(s))
import code
code.interact(local=dict(globals(), **locals()))
