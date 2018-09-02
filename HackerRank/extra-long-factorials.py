
def fact(m):
    if(m==0):
        return 1
    return m*fact(m-1)

n=int(input())
print (fact(n))