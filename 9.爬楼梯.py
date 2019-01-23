# 题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
def getway(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    else:
        return getway(n-1)+getway(n-2)

n=eval(input("请输入楼梯阶数n:"))
print(getway(n))
        
