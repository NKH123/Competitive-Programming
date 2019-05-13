
def Gcd(a, b):
	if a>b:
		t=a
		a=b
		b=t
	if a==0:
		return b
	else:
		return Gcd(b%a,a)
def lcm(a):
	mul=1
	for i in range(len(a)):
		mul=mul*a[i]
	gcd=0
	for i in range(len(a)):
		gcd=Gcd(gcd,a[i])
	ans=mul//gcd
	print(gcd)
	return ans








a=input().split()
for i in range(len(a)):
	a[i]=int(a[i])
LCM=1
for i in range(len(a)):
	b=[0,0]
	b[0]=LCM
	b[1]=a[i]
	LCM=lcm(b)
print(LCM)