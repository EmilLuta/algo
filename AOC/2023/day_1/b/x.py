x = {
    "1": 1,
    "2": 2,
    "3": 3,
    "4": 4,
    "5": 5,
    "6": 6,
    "7": 7,
    "8": 8,
    "9": 9,
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9
}

lines = []

with open("input_1.txt", 'r') as f:
    lines = f.readlines()

answer = 0

for line in lines:
    indices = []
    for s in x:
        i = line.find(s)
        if i != -1:
            indices.append((i, x[s]))
    indices.sort()
    answer += indices[0][1] * 10 + indices[-1][1]

print(answer)
