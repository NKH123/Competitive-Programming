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
strr = "100 44 114 115 44 141 62 140 44 114 115 44 100 66 66 66 13 66 44 114 115 44 124 216 214 220 216 215 203 215 224 223 44 114 115 44 100 66 163 111"
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