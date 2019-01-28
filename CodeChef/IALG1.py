t=int(input())
while t>0:
	a,b=int(input().split())
	#b=int(input())
	a=a*(10**100)
	ans=a/b
	#print("ans=",ans)
	a1=int(ans%(10**100))
	a2=int(ans//(10**100))
	print(a2,end="")
	print(".",end="")
	print(a1)








	t=t-1