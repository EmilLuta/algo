import matplotlib.pyplot as plt

with open('plot.txt', 'r') as f:
    x = f.read()
a = x.split('\n')
a = a[:-1]
x = []
y = []
for i in a:
    h = i.split(' ')
    x.append(int(h[0]))
    y.append(int(h[1]))
plt.plot(x, y)
plt.show()
