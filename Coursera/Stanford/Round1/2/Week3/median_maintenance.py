import heapq

def load_data():
    data = []
    with open('input.txt', 'r') as f:
        for line in f:
            data.append(int(line.strip()))
    return data

data = load_data()
h_l = []
h_r = []

s = 0

for item in data:
    if len(h_l) == 0:
        heapq.heappush(h_l, -1 * item)
    elif len(h_l) == 1 and len(h_r) == 0:
        x = heapq.heappop(h_l) * -1
        if x > item:
            heapq.heappush(h_r, x)
            heapq.heappush(h_l, -1 * item)
        else:
            heapq.heappush(h_r, item)
            heapq.heappush(h_l, -1 * x)
    else:
        top_l = h_l[0] * -1
        top_r = h_r[0]
        if len(h_l) == len(h_r) + 1:
            if item >= top_l:
                heapq.heappush(h_r, item)
            else:
                x = heapq.heappop(h_l) * -1
                heapq.heappush(h_l, -1 * item)
                heapq.heappush(h_r, x)
        else:
            if item <= top_r:
                heapq.heappush(h_l, -1 *item)
            else:
                x = heapq.heappop(h_r)
                heapq.heappush(h_r, item)
                heapq.heappush(h_l, -1 * x)
    s += h_l[0] * -1
print(s % 10000)

