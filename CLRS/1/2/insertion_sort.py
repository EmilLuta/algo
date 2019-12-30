def insertion_sort(a):
    for j in range(1, len(a)):
        i = j - 1
        value = a[j]
        while i >= 0 and value < a[i]:
            a[i + 1] = a[i]
            i -= 1
        a[i + 1] = value
    return a

def insertion_sort_reverse(a):
    for j in range(1, len(a)):
        i = j - 1
        value = a[j]
        while i >= 0 and value > a[i]:
            a[i + 1] = a[i]
            i -= 1
        a[i + 1] = value
    return a

print(insertion_sort([5, 2, 4, 6, 1, 3]))
print(insertion_sort_reverse([5, 2, 4, 6, 1, 3]))
