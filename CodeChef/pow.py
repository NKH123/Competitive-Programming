def fastpow( a, b):
	if b==1:
		return a
	else:
		if b%2==0:
			A=fastpow(a,b//2)
			return A*A
		else:
			A=fastpow(a,b//2)
			B=a*A
			return B*A
			

while True:
	n,m=map(int,input().split())
	print(fastpow(n,m))