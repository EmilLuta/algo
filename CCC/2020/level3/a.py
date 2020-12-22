from math import cos, e, pi, sin, sqrt
from sys import argv

filename = argv[1]

with open(filename, 'r') as f:
    n = int(f.readline())
    coords = []
    for _ in range(n):
        coords.append([float(i) for i in f.readline().split(',')])

out = filename.split('.')[0]

with open(f'{out}.out', 'w+') as w:
    r = 63780000
    # b = 6356000
    for c in coords:
        lat, lon, alt = c
        # f = 1.0/298.257223563
        f = 1
        cosLat = cos(lat)
        sinLat = sin(lat)
        FF     = (1.0-f)**2
        C      = 1/sqrt(cosLat**2 + FF * sinLat**2)
        S      = C * FF
        x = (r * C + alt)*cosLat * cos(lon)
        y = (r * C + alt)*cosLat * sin(lon)
        z = (r * S + alt)*sinLat
        w.write(f'{x} {y} {z}\n')


# var cosLat = Math.cos(lat * Math.PI / 180.0);
# var sinLat = Math.sin(lat * Math.PI / 180.0);
# var cosLon = Math.cos(lon * Math.PI / 180.0);
# var sinLon = Math.sin(lon * Math.PI / 180.0);
# var rad = 500.0;
# marker_mesh.position.x = rad * cosLat * cosLon;
# marker_mesh.position.y = rad * cosLat * sinLon;
# marker_mesh.position.z = rad * sinLat;
