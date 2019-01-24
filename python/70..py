#题目：编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用函数1/1+1/3+...+1/n
def f(n):
    if n%2==0:
        s=0
        for i in range(1,n+1): 
            s=s+(1/(n*2))
        return s
    if n%2!=0:
        s=0
        for j in range(1,n+1):
            s=s+(1/(n*2-1))
        return s

n=int(input("Input n:"))
print(f(n))
