def f(x):
    if x==0:
        return 1
    else:
        return (x*f(x-1)) 


print("5!=",f(5))
