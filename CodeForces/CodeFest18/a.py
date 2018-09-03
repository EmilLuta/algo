def go():
    n = int(input())
    return len(bin(n)) - 2
print(go())
