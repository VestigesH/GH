#题目：将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
n=int(input("请输入一个正整数n:"))
N=n
print(N,"=",end="")
while N>=2:
    for i in range (2,n+1):
        if n%i==0:
            n=n//i
            if n==1:
                print(i,end="")
            else:
                print(i,"*",end="")
            break
else:
    print("输入错误")
