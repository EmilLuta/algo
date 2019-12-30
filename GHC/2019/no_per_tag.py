files = ['a_example.txt', 'b_lovely_landscapes.txt', 'c_memorable_moments.txt', 'd_pet_pictures.txt', 'e_shiny_selfies.txt']

files = ['b_lovely_landscapes.txt']

for fi in files:
    t = {}
    with open(fi) as f:
        for i in f.readlines():
            a = i.split(' ')
            if len(a) == 1:
                n = int(a[0])
            else:
                tags = int(a[1])
                tags = a[2:]
                for tag in tags:
                    tag = tag.replace('\n', '')
                    t.setdefault(tag, 0)
                    t[tag] += 1
    print(fi)
    for tag in t:
        print("{}: {}".format(tag, t[tag]))
