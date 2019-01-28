


def b2d(n):
	a=[]
	while n>0:
		if(n%2==1):
			a.append(1)
		else:
			a.append(0)
		n=n//10
	b=0
	for i in range(len(a)):
		if a[i]==1:
			b=b+2**i
	return b
















while(True):
	n=int(input("Enter binary number: "))
	print(b2d(n))