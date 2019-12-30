def load_scheduler_data():
    data = []
    with open('input_scheduler.txt', 'r') as f:
        next(f)
        for line in f:
            data.append([int(i) for i in line.split(' ')])
    return data


def scheduler_one():
    data = load_scheduler_data()
    data.sort(key = lambda x: (x[0] - x[1], x[0]), reverse=True)
    time = total = 0
    for entry in data:
        time += entry[1]
        total += time * entry[0]
    return total

def scheduler_two():
    data = load_scheduler_data()
    data.sort(key = lambda x: (x[0]/x[1]), reverse=True)
    time = total = 0
    for entry in data:
        time += entry[1]
        total += time * entry[0]
    return total
print(scheduler_one())
print(scheduler_two())

