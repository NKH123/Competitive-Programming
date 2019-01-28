


def d2b(n):
	a=[]
	if(n==0):
		return 0
	while n>0:
		if n%2==1:
			a.append(1)
		else:
			a.append(0)
		n=n//2
	b=0
	for i in range(len(a)-1,-1,-1):
		b=10*b+a[i]
	return b












while(True):
	n=int(input("Enter decimal number: "))
	print(d2b(n))