a = [int(i) for i in input().split(' ')]
answer = 0
for x in range(20):
    for i in a:
        answer += abs(x - i)
    print(f'make it {x} = {answer}')
    answer = 0
