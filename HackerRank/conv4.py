def val(c): 
    if c >= '0' and c <= '9': 
        return ord(c) - ord('0') 
    else: 
        return ord(c) - ord('A') + 10; 
  
# Function to convert a number  
# from given base 'b' to decimal  
def toDeci(str,base): 
    llen = len(str) 
    power = 1 #Initialize power of base 
    num = 0     #Initialize result 
  
    # Decimal equivalent is str[len-1]*1 +  
    # str[len-1]*base + str[len-1]*(base^2) + ...  
    for i in range(llen - 1, -1, -1): 
          
        # A digit in input number must  
        # be less than number's base  
        if val(str[i]) >= base: 
            print('Invalid Number') 
            return -1
        num += val(str[i]) * power 
        power = power * base 
    return num 
def toChar(a):
    return chr(int(a))    
# Driver code 
strr = "55 66 62 66 56 62 55 100 62 66 56 62 55 100 62 100 56 62 55 101 62 100 56 62 55 102 62 100 56 62 55 102 62 66 56 44 166 222 203 44 224 206 203 44 201 216 215 215 203 201 224 44 220 216 210 215 224 223 44 230 206 210 201 206 44 214 166 212 203 44 224 206 203 44 214 166 231 210 214 225 214 44 223 225 214"
strrr=list(strr.split(' '))
print (strr)
base = 7
chrr=[]
for i in strrr:
    print("i=",i)
    j=toDeci(i,base)
    chrr.append(j)
print(chrr)
let=[]
for i in chrr:
    j=toChar(i)
    let.append(j)
for i in let:
    print(i,end="")



#print('Decimal equivalent of', strr,  
  #            'in base', base, 'is',  
        #         toDeci(strr, base)) 
  
# This code is contributed  
# by sahil shelangia 