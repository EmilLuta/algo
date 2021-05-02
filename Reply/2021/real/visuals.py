import numpy as np
import matplotlib.pyplot as plt
import sys

with open(sys.argv[1], 'r') as f:
    f.readline()
    h = [int(i) for i in f.readline().split(' ')]
    n = h[0]
    m = h[1]
    x = []
    y = []
    for i in range(n):
        w = f.readline()
        a = [int(x) for x in w.split(' ')]
        x.append(a[0])
        y.append(a[1])

with open(sys.argv[2], 'r') as f:
    n = int(f.readline().strip())
    xx = []
    yy = []
    for i in range(n):
        a = [int(z) for z in f.readline().strip().split(' ')]
        xx.append(a[1])
        yy.append(a[2])

plt.scatter(x, y, c='b', s=1)
plt.scatter(xx, yy, c='r', s=1)
plt.show()
