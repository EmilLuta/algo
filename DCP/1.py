def two_sum(l, k):
    s = set()
    for i in l:
        key = k - i
        if key in s:
            return True
        s.add(i)
    return False


