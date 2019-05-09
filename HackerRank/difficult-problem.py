t=int(input())
while t>0:
	n,k=input().split()
	n=int(n)
	a=input()
	n=n-2
	x=(n)*(n+1)*(n+2)
	x=x//6
	ans=x*x
	ans=ans%(1000000007)
	print(ans)




	t=t-1