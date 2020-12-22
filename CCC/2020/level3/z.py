from math import sqrt, sin, cos

lat, lon, h = 49.828, 7.714, 11277.0

f = 1 / 298.257223563
a = 6378000
b = a * (1 - f)
e = sqrt(((a ** 2) - (b ** 2)) / a ** 2)
N = a / sqrt(1 - (e ** 2) * (sin(lat) ** 2))

x = (N + h) * cos(lat) * cos(lon)
y = (N + h) * cos(lat) * sin(lon)
z = (((b ** 2) / (a ** 2)) * N + h) * sin(lat)
print(x, y, z)
