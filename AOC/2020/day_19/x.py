with open('input.txt', 'r') as f:
    lines = f.read().split('\n')
    all_len = len("bbaaaaaabababbbbbbaabbbb")
    count = 0
    for line in lines:
        n = len(line)
        if n != all_len and n % all_len == 0:
            count += 1
    print(count)
