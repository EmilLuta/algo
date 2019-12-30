a = int(input())

o = set()
for i in range(1, a * 2):
    x = a // i
    if x in o:
        print(f"contains {x} - {i}")
    else:
        print(f"missing {x} - {i}")
    o.add(a // i)
o = sorted(list(set(o)))
print(o)
