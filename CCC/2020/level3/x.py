import math

def gps_to_ecef(latitude, longitude, altitude):
    # (lat, lon) in WSG-84 degrees
    # h in meters

    R = 6378000
    # f_inv = 298.257224
    f_inv = 1000
    f = 1.0 / f_inv
    e2 = 1 - (1 - f) * (1 - f)
    cosLat = math.cos(latitude * math.pi / 180)
    sinLat = math.sin(latitude * math.pi / 180)

    cosLong = math.cos(longitude * math.pi / 180)
    sinLong = math.sin(longitude * math.pi / 180)

    c = 1 / math.sqrt(cosLat * cosLat + (1 - f) * (1 - f) * sinLat * sinLat)
    s = (1 - f) * (1 - f) * c

    x = (R*c + altitude) * cosLat * cosLong
    y = (R*c + altitude) * cosLat * sinLong
    z = (R*s + altitude) * sinLat

    return x, y, z

print(gps_to_0000049.828,7.714,11277.0))
