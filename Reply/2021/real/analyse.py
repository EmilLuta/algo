import sys
from collections import defaultdict

with open(sys.argv[1], 'r') as f:
    a = f.read()
    a = a.split('\n')[1:-1]
    a = [[int(i) for i in x.split(' ')] for x in a]
    m = defaultdict(int)
    m_p = defaultdict(int)
    for u in a:
        m[u[0]] += 1
        m[(u[1], u[2])] += 1
    for k in m:
        if m[k] > 1:
            print(k)
    for k in m_p:
        if m_p[k] > 1:
            print(k)
