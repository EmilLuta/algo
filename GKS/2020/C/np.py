from itertools import product
import numpy as np

n, m = 5, 3

x = product('ABCDE', repeat=n*m)
x = np.reshape(list(x), (-1, n, m))
print(x)
