import math as m
t=int(input())
# a=m.floor(5.999999999999999999)
# print(a)
# for i in range(50,70):
# 	ll=m.floor(i*(1+(5**(0.5)))/2)
# 	print(i, ll)

while t>0:
	a,b=input().split()
	a=int(a)
	b=int(b)
	if(a>b):
		tt=a
		a=b
		b=tt
	ll=m.floor(a*(1+(5**(0.5)))/2)
	if b>ll or a==b:
		print("Ari")
	else:
		print("Rich")
	t=t-1
	# print(t)
# print("yo")
