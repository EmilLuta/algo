a = int(input())

output = []
for i in range(1, a + 1):
    if a % i == 0:
        output.append(i)
print(output)
