while True:
	n=int(input())
	sum=0
	for i in range(1,n+1):
		sum=sum+1/i
	sum=n*sum
	print(sum)
