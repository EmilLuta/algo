def gcd(x, y):

   while(y):
       x, y = y, x % y
   return x

def lcm(x, y):
   lcm = (x*y)//gcd(x,y)
   return lcm

for n in range(2, 100):
# for n in range(9, 10):
    m = float('inf')
    a = None
    b = None
    for i in range(1, n):
        x = i
        y = n - i
        l = lcm(x, y)
        if l < m:
            m = l
            a = x
            b = y
    print(f'min_lcm = {m}, a = {a}, b = {b} for n = {n}')
