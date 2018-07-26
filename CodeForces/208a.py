def go():
    n = input().split('WUB')
    n = [i for i in n if i != '']
    return ' '.join(n)
print(go())
