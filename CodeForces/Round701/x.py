t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split(' ')]
    answers = [[a[0]]]
    for i in range(1, n):
        new_answers = []
        for j in range(len(answers)):
            w = answers[j][:]
            sum_so_far = sum(w)
            dif = a[i] - sum_so_far
            if dif != a[i]:
                y = answers[j][:]
                y.append(a[i])
                new_answers.append(y)
            w.append(dif)
            new_answers.append(w)
        answers = new_answers
    print(f"got {len(answers)}")
    for x in answers:
        print(x)
