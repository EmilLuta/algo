files = ['a_example.txt', 'b_lovely_landscapes.txt', 'c_memorable_moments.txt', 'd_pet_pictures.txt', 'e_shiny_selfies.txt']

for fi in files:
    h = 0
    v = 0
    with open(fi) as f:
        for i in f.readlines():
            a = i.split(' ')
            if a[0] == 'H':
                h += 1
            if a[0] == 'V':
                v += 1
    print(fi)
    print(h)
    print(v)
