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

# def run(libraries, b, l, d, books):
#     day = 0
#     index = 0
#     while day < d and index < l:
#         day += libraries[index].signup
#         libraries[index].go_from = day
#         index += 1
#     out = []
#     seen = set()
#     for j in range(index):
#         lib = libraries[j]
#         books_can_go = lib.books[:min((day - lib.go_from) * lib.per_day, lib.b)]
#         if len(books_can_go) == 0:
#             continue
#         out.append((lib.id, books_can_go))
#         seen = set(list(seen) + books_can_go)
#     return sum(books[i] for i in seen), out

# def write(out):
#     global file_name, books
#     with open(f'{file_name[0]}.out', 'w+') as f:
#         f.write(str(len(out)) + '\n')
#         points = 0
#         for x in out:
#             if len(x[1]) == 0:
#                 continue
#             f.write(f'{x[0]} {len(x[1])}\n')
#             f.write(' '.join(str(i) for i in x[1]))
#             f.write('\n')
#             points += sum(books[i] for i in x[1])

if __name__ == '__main__':
    books_taken = set()
    libraries, b, l, d, books = read_input()
    taken = set()
    from collections import defaultdict
    libs = defaultdict(list)
    for lib in libraries:
        lib.books = set(lib.books)
    for lib in libraries:
        if len(taken.union(lib.books)) >= len(taken) + len(lib.books) * 1:
            for buk in lib.books:
                if buk not in taken:
                    libs[lib].append(buk)
                    taken.add(buk)
    answer = list(libs.keys())
    answer.sort(key=lambda lib: -(sum(books[i] for i in lib.books) / lib.signup))
    for lib in answer:
        lib.books = list(lib.books)
        lib.books.sort(key=lambda k: -books[k])
    with open(f'{file_name[0]}.out', 'w+') as f:
        day = 0
        index = 0
        output = {}
        while day < d:
            lib = answer[index]
            day += lib.signup
            index += 1
            output[lib.id] = lib.books[:min((d - day) * lib.per_day, lib.b)]
        f.write(str(len(output)) + '\n')
        points = 0
        for key, value in output.items():
            f.write(f'{key} {len(value)}\n')
            f.write(' '.join(str(i) for i in value))
            f.write('\n')
            points += sum(books[i] for i in value)
    print(f'{points}/{sum(books)}')


    import code
    code.interact(local=dict(globals(), **locals()))
