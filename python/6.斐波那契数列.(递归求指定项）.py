def f(n):
    if n==1 or n==2:
        return 1
    else:
        return f(n-1)+f(n-2)
n=int(input("请输入项数n:"))
print(f(n))
