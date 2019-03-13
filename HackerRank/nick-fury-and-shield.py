n,x=[int(x) for x in input().split()]
#print(n, x)
largest=(10**(n))-1
smallest=10**(n-1)
#sans,lans
sans=smallest-smallest%x
if smallest%x!=0:
	sans+=x
lans=largest-(largest%x)
avg=(sans+lans)//2
print(sans,lans)
print(largest,smallest)
app=0
if (sans+lans)%2 ==0:
	app=0
else:
	app=5
print(avg,end="")
print(".",end="")
print(app)
