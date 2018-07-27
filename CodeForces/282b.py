n=int(input())
x=0
for i in range(n):
	a=int(input().split()[0])
	x+=a
r=round(x/1000)
print('A'*(n-r)+'G'*r)
