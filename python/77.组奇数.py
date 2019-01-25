#用0-7的数组成的奇数个数
s= 1
L=[]
S=0
for i in range(1,9):#i为组成奇数的位数
    if i==1:
        s=4
    elif i==2:
        s=4*7
        if i>2:
            s*=8
    S=S+s
    L.append(S)
print("组成奇数个数为:",sum(L))

