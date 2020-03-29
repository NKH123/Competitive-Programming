"""
ID: your_id_here
LANG: PYTHON3
TASK: gift1
"""


fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

a = int (fin.readline())

name = []
for i in range(a):
    name.append(fin.readline())


with open('gift1.in') as f:
   size=sum(1 for _ in f)

print (size)
money= [0]*a




temp = 0

while temp <size-a:

    pg = fin.readline() #person who is giving
    temp = temp+1

    for i in range(a):
        if(name[i] == pg):
            mon = fin.readline()
            temp=temp+1
            mon = mon.split()
            tot = int(mon[0])
            peo = int(mon[1])
            if peo==0:
                break
            money[i] = money[i] - peo*int(tot/peo)
            for _ in range(peo):
                pr = fin.readline() #person who is receiving
                temp = temp + 1
                op= -1
                while (op<a-1):
                    op=op+1
                    if (pr == name[op]):
                        money[op] = money[op]+int(tot/peo)




print (money)
for ti in range(a):
    name[ti] = name[ti].strip('\n')
for i in range(a):
    fout.write(str(name[i])+ " "+ str(money[i]) + "\n")
