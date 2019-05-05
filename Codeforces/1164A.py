a=0
b=4
c=-1
n=2
while True:
	n=n+1
	c=4*b-3*a
	a=b
	b=c
	print(c)
	
	if c%83==0:
		break
print(c)
print(n)

