def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)



while True:
	n,m=map(int,input().split())
	print(gcd(n,m))