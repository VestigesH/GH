#题目：编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,当输入n为奇数时，调用函数1/1+1/3+...+1/n
def f(n):
    s=0
    if n%2==0:
        for i in range(2,n+2,2): 
            s=s+(1/i)
        return s
    else:
        for i in range(1,n+2,2):
            s=s+(1/i)
        return s

n=int(input("Input n:"))
print(f(n))
