import math

def get_x_y_z(lat, lon, alt):
    rho = 6378000
    x = math.cos(lat) * math.cos(lon) * rho
    y = math.cos(lat) * math.sin(lon) * rho
    z = math.sin(lat) * rho
    return x, y, z

print(get_x_y_z(49.828,7.714,11277.0))
