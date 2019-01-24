#题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
n=int(input("请输入一个正整数n:"))
N=n
List=[]
for i in range(1,int(n/2)+1):#判断因数的次数
    if n%i==0:
        if i==1:
            List.append(str(i))
            n=n/i
        else:
            break
s="*".join(List)
print(N,"=",s)
