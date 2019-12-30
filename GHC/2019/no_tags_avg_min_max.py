files = ['a_example.txt', 'b_lovely_landscapes.txt', 'c_memorable_moments.txt', 'd_pet_pictures.txt', 'e_shiny_selfies.txt']

for fi in files:
    minimum = float('inf')
    maximum = float('-inf')
    s_tag = 0
    n = None
    with open(fi) as f:
        for i in f.readlines():
            a = i.split(' ')
            if len(a) == 1:
                n = int(a[0])
            else:
                tags = int(a[1])
                s_tag += tags
                minimum = min(minimum, tags)
                maximum = max(maximum, tags)
    print(fi)
    print("Minimum: {}; Maximum: {}; Average: {};".format(minimum, maximum, s_tag/ n))
