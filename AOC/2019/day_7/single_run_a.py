import subprocess

a = [4,3,2,1,0]
inp = '0\n'
for x in a:
    inp = f'{x}\n' + inp
    process = subprocess.run(['./a.out'], stdout=subprocess.PIPE, stderr=subprocess.PIPE, input=inp.encode('utf-8'))
    if len(process.stderr) > 0:
        raise ValueError(stderr.decode('utf-8'))
    inp = process.stdout.decode("UTF-8")
print(int(inp.strip()))
