


def pow(a, b):
	if b==0:
		return 1
	else:
		ret=pow(a,b//2)
		ret=ret*ret
		if(b%2==1):
			ret=a*ret
		return ret


def gcd(a, b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)













t=int(input())
while t>0:
	a,b=[int(x) for x in input().split()]
	if a%2==0 or b%2==0:
		print(2)
	else:
		print(12)
	t=t-1
	# for a in range(1,101):
	# 	for b in range(1, 101):
	# 		A=gcd(a,b)
	# 		if A==1:
	# 			print(a, b)

	# 			# print("a=",a)
	# 			# print("b=",b)
	# 			A=pow(5,a)+pow(7,a)
	# 			B=pow(7,b)+pow(5,b)
	# 			ans=gcd(A,B)
	# 			print(ans)
	# t=t-1

	# a=int(a)
	# b=int(b)
	# # print("a=",a)
	# # print("b=",b)
	# A=pow(5,a)+pow(7,a)
	# B=pow(7,b)+pow(5,b)
	# ans=gcd(A,B)
	# print(ans)
	# t=t-1