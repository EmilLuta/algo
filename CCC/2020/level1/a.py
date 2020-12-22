from sys import argv

filename = argv[1]

with open(filename, 'r') as f:
    lines = f.read().split('\n')
    n = int(lines[0])

max_alt = 0
max_lat = float('-inf')
min_lat = float('inf')
max_lng = float('-inf')
min_lng = float('inf')
max_timestamp = float('-inf')
min_timestamp = float('inf')
for i in range(1, n + 1):
    timestamp, lat, lng, alt = [float(i) for i in lines[i].split(',')]
    max_timestamp = max(max_timestamp, timestamp)
    min_timestamp = min(min_timestamp, timestamp)
    max_lat = max(max_lat, lat)
    min_lat = min(min_lat, lat)
    max_lng = max(max_lng, lng)
    min_lng = min(min_lng, lng)
    max_alt = max(max_alt, alt)

out = filename.split('.')[0]

with open(f'{out}.out', 'w+') as f:
    f.write(f'{int(min_timestamp)} {int(max_timestamp)}\n{min_lat} {max_lat}\n{min_lng} {max_lng}\n{max_alt}\n')

