def load_data():
    with open('input.txt', 'r') as f:
        return [int(i.replace('\n', '')) for i in f.readlines()]

counter = 0
def quicksort(a, start, end):
    global counter
    if start >= end:
        return
    counter += end - start
    # MEDIAN OF THREE PIVOT
    # x = a[start]
    # z = a[end]
    # middle = start + (end - start) // 2
    # y = a[middle]
    # if (x < z and z < y) or (x > z and z > y):
    #     a[start], a[end] = a[end], a[start]
    # if (x < y and y < z) or (x > y and y > z):
    #     a[start], a[middle] = a[middle], a[start]
    # LAST ELEMENT PIVOT
    # a[start], a[end] = a[end], a[start]

    # FIRST ELEMENT PIVOT
    pivot = a[start]
    i = start + 1
    for j in range(start + 1, end + 1):
        if a[j] < pivot:
            a[i], a[j] = a[j], a[i]
            i += 1
        j += 1
    a[start], a[i - 1] = a[i - 1], a[start]
    quicksort(a, start, i - 2)
    quicksort(a, i, end)

a = load_data()
quicksort(a, 0, len(a) - 1)
print(a)
print(counter)
