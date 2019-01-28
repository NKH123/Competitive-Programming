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
strr = "155 216 225 44 166 222 203 44 205 210 226 203 215 44 166 44 205 222 210 202 44 216 204 44 223 210 233 203 44 141 231 140 62 44 232 216 225 44 206 166 226 203 44 224 216 44 204 210 215 202 44 224 206 203 44 223 225 214 44 216 204 44 224 206 203 44 214 166 231 210 214 225 214 44 201 216 215 215 203 201 224 203 202 44 201 216 214 220 216 215 203 215 224 223 64 13 13 150 230 216 44 124 203 213 213 44 216 204 44 224 206 203 44 205 222 210 202 44 210 223 44 201 216 215 215 203 201 224 203 202 44 210 204 44 224 206 203 232 44 103 63 202 210 222 203 201 224 210 216 215 63 230 210 223 203 44 166 202 211 166 201 203 215 224 44 166 215 202 44 200 216 224 206 44 216 204 44 224 206 203 214 44 166 222 203 44 215 216 215 63 233 203 222 216 64 13 13 141 216 224 203 112 44 205 222 210 202 160 66 162 160 66 162 44 166 215 202 44 205 222 210 202 160 215 63 100 162 160 66 162 44 166 222 203 44 215 216 224 44 201 216 215 215 203 201 224 203 202 44 166 215 202 44 223 210 214 210 213 166 222 13 13 140 216 224 210 226 166 224 210 216 215 44 224 216 44 203 215 201 222 232 220 224 44 204 222 216 214 44 201 216 202 203 204 216 222 201 203 223 44 100 106 100 130 55 210 224 44 230 166 223 44 166 201 224 225 166 213 213 232 44 204 225 215 44 224 216 44 223 216 213 226 203 56"
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