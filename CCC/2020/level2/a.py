from collections import defaultdict
from sys import argv

filename = argv[1]


class Flight:

    i = 1

    def __init__(self, t, lat, lng, alt, src, dst, start):
        self.id = self.i
        self.i += 1
        self.t = t
        self.lat = lat
        self.lng = lng
        self.alt = alt
        self.src = src
        self.dst = dst
        self.start = start

    def read(f):
        info = f.readline().strip().split(',')
        return Flight(
            int(info[0]),
            float(info[1]),
            float(info[2]),
            float(info[3]),
            info[4],
            info[5],
            int(info[6]),
        )

planes = []

with open(filename, 'r') as f:
    n = int(f.readline())
    for i in range(1, n + 1):
        planes.append(Flight.read(f))

flights = defaultdict(set)

for plane in planes:
    flight_info = (plane.src, plane.dst)
    flights[flight_info].add(plane.start)

out = filename.split('.')[0]

with open(f'{out}.out', 'w+') as f:
    for key in sorted(flights.keys()):
        f.write(f'{key[0]} {key[1]} {len(flights[key])}\n')
