
mod=1000000007

def fastpow( a, b):
	if b==1:
		return a
	if b==0:
		return 1
	else:
		if b%2==0:
			A=fastpow(a,b//2)
			return A*A
		else:
			A=fastpow(a,b//2)
			B=a*A
			return B*A

def fastmod( a, b):
	if b==1:
		return a%mod
	if b==0:
		return 1
	else:
		if b%2==0:
			A=fastmod(a,b//2)
			return ((A%mod)*(A%mod))%mod
		else:
			A=fastmod(a,b//2)
			B=((a%mod)*(A%mod))%mod
			return ((B%mod)*(A%mod))


def gcd(a,b):
	if a==0:
		return b
	return gcd(b%a,a)


t=int(input())

while t>0:
	
	n,k,m=map(int,input().split())
	
	ans=0
	if m%2==1:
		
		K=m//2
		K=K+1
		A=fastmod(n,K)
		
		num=(A-fastmod(n-1,K)+2*mod)%mod
		
		den=A

		G=gcd(num,den)
		num=num//G
		den=den//G 
		#print(num)
		#print(den)
		num=num%mod
		den=fastmod(den,mod-2)
		ans=((num%mod)*(den%mod))%mod
		
	else:
		
		M=m//2
		M=M-1
		A=fastmod(n,M)
		
		num=(n+k)*(A)+(n-1)*(A)+(n-1)*(n+k-1)*((A-fastmod(n-1,M)+2*mod)%mod)
		den=A*(n+k)*n
		print(num)
		#print()
		print(den)
		G=gcd(num,den)
		num=num//G
		den=den//G 
		print(num)
		print(den)
		num=num%mod
		den=fastmod(den,mod-2)
		ans=((num%mod)*(den%mod))%mod
	#print("I'm here")
	print(ans)
	t=t-1