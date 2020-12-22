from sys import argv

file_name = argv[1]


class Library:
    def read(self, f, i):
        b, signup, per_day = [int(i) for i in f.readline().split(' ')]
        self.b = b
        self.signup = signup
        self.per_day = per_day
        self.books = [int(i) for i in f.readline().split(' ')]
        self.id = i
        return self

    def __str__(self):
        return f'Library #{self.id} -> (books: {self.b}, signup: {self.signup}, delivery per day: {self.per_day}'

    def __repr__(self):
        return f'Library #{self.id} -> (books: {self.b}, signup: {self.signup}, delivery per day: {self.per_day})'

def read_input():
    global file_name
    libraries = []

    with open(file_name, 'r') as f:
        b, l, d = [int(i) for i in f.readline().split(' ')]
        books = [int(i) for i in f.readline().split(' ')]
        for i in range(l):
            lib = Library().read(f, i)
            if lib.signup >= d:
                continue
            libraries.append(lib)

    for lib in libraries:
        lib.books.sort(key=lambda k: -books[k])
    return libraries, b, l, d, books

def run(libraries, b, l, d, books):
    day = 0
    index = 0
    while day < d and index < l:
        day += libraries[index].signup
        libraries[index].go_from = day
        index += 1
    out = []
    seen = set()
    for j in range(index):
        lib = libraries[j]
        books_can_go = lib.books[:min((day - lib.go_from) * lib.per_day, lib.b)]
        if len(books_can_go) == 0:
            continue
        out.append((lib.id, books_can_go))
        seen = set(list(seen) + books_can_go)
    return sum(books[i] for i in seen), out


def write(out):
    global file_name, books
    with open(f'{file_name[0]}.out', 'w+') as f:
        f.write(str(len(out)) + '\n')
        points = 0
        for x in out:
            if len(x[1]) == 0:
                continue
            f.write(f'{x[0]} {len(x[1])}\n')
            f.write(' '.join(str(i) for i in x[1]))
            f.write('\n')
            points += sum(books[i] for i in x[1])


if __name__ == '__main__':
    books_taken = set()
    libraries, b, l, d, books = read_input()
    from random import shuffle
    my_best = 0
    for i in range(10000):
        shuffle(libraries)
        value, out = run(libraries, b, l, d, books)
        if my_best < value:
            my_best = value
            print(f'{value}/{sum(books)}')
            write(out)
    # day = 0
    # index = 0
    # while day < d and index < l:
    #     day += libraries[index].signup
    #     libraries[index].go_from = day
    #     index += 1
    # out = []
    # for j in range(index):
    #     lib = libraries[j]
    #     books_can_go = lib.books[:min((day - lib.go_from) * lib.per_day, lib.b)]
    #     if len(books_can_go) == 0:
    #         print('continued')
    #         continue
    #     out.append((lib.id, books_can_go))
    # with open(f'{file_name[0]}.out', 'w+') as f:
    #     f.write(str(len(out)) + '\n')
    #     points = 0
    #     seen = set()
    #     for x in out:
    #         if len(x[1]) == 0:
    #             continue
    #         f.write(f'{x[0]} {len(x[1])}\n')
    #         f.write(' '.join(str(i) for i in x[1]))
    #         f.write('\n')
    #         # import code
    #         # code.interact(local=dict(globals(), **locals()))
    #         seen = set(x[1] + list(seen))
    #         points += sum(books[i] for i in x[1])
    # print(f'Got {sum(books[i] for i in seen)}/{sum(books)}.')

