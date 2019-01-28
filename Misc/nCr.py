

def nCr(n,r):
	if n==r:
		return 1
	if r==0:
		return 1
	if r==1:
		return n 
	return nCr(n-1,r)+nCr(n-1,r-1)







n=int(input("Input n: "))
r=int(input("Input r: "))
print(nCr(n,r))