import numpy as np
while True:
	k,n=input().split()
	n=int(n)
	k=int(k)
	k=np.ceil(k/2)
	k=int(k)
	ans=0
	f=2
	ans=0
	n=n-1
	while n>0:
		ans+=((-1)**(f))*(n**k)
		n=n-1
		if f==2:
			f=1
		else:
			f=2
	print(2*ans)

