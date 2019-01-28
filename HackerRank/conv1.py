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
strr = "130 210 222 223 224 44 136 210 215 203 44 201 216 215 224 166 210 215 223 44 224 230 216 44 210 215 224 203 205 203 222 223 44 141 44 166 215 202 44 140 62 13 141 203 231 224 44 141 44 213 210 215 203 223 44 201 216 215 224 166 210 215 223 44 140 44 210 215 224 203 205 203 222 223 44 166 223 44 201 216 214 220 216 215 203 215 224 223 44 216 204 44 224 206 203 44 205 222 210 202"
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