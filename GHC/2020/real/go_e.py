from sys import argv
from collections import defaultdict

file_name = argv[1]


class Library:
    def read(self, f, i):
        b, signup, per_day = [int(i) for i in f.readline().split(' ')]
        self.b = b
        self.signup = signup
        self.per_day = per_day
        self.books = [int(i) for i in f.readline().split(' ')]
        self.id = i
        self.index = 0
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
    go_from = defaultdict(list)
    while day < d and index < l:
        day += libraries[index].signup
        go_from[day] = libraries[index]
    libs = []
    seen = set()
    out = defaultdict(list)
    for i in range(d):
        if i in go_from:
            libs.append(go_from[i])
        for j in range(len(libs)):
            lib = libs[j]
            if lib is None:
                continue
            if lib.index >= lib.b:
                libs[j] = None
                continue
            deliver = lib.per_day
            while deliver > 0 and lib.index < lib.b:
                if lib.books[lib.index] not in seen:
                    our_book = lib.books[lib.index]
                    seen.add(our_book)
                    out[lib.id].append(our_book)
                    deliver -= 1
                lib.index += 1
            if lib.index >= lib.b:
                libs[j] = None
    return out

def write(out):
    global file_name, books
    with open(f'{file_name[0]}.out', 'w+') as f:
        f.write(str(len(out)) + '\n')
        for key, value in out.items():
            f.write(f'{key} {len(value)}\n')
            f.write(' '.join(str(i) for i in value))
            f.write('\n')


def get_points(out):
    points = 0
    for key, value in out.items():
        points += sum(books[i] for i in value)
    return points

if __name__ == '__main__':
    books_taken = set()
    libraries, b, l, d, books = read_input()
    points = 0
    all_points = sum(books)
    for i in range(100):
        from random import shuffle
        shuffle(libraries)
        out = run(libraries, b, l, d, books)
        curr = get_points(out)
        if curr > points:
            write(out)
            points = curr
            print(f'{points}/{all_points}')

    # import code
    # code.interact(local=dict(globals(), **locals()))
    # from random import shuffle
    # my_best = 0
    # for i in range(10000):
        # shuffle(libraries)
        # value, out = run(libraries, b, l, d, books)
        # if my_best < value:
            # my_best = value
            # print(f'{value}/{sum(books)}')
            # write(out)
