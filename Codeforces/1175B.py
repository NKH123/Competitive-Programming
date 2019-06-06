MAX=(1<<32)-1
f=0
ans=0
def ADD(p):
	global ans,f
	ans=ans+p
	if ans>MAX:
		f=1

l=int(input())
arr=[1]
while l>0:
	s=input()
	if s[0]=='f':
		s,n=s.split()
		n=int(n)
		add=arr[len(arr)-1]*n
		arr.append(add)
	elif s[0]=='e':
		arr.pop()
	elif s[0]=='a':
		ADD(arr[len(arr)-1])
		


	l=l-1
if(f==1):
	print("OVERFLOW!!!")
else:
	print(ans)