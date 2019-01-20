# 题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
n=eval(input("请输入楼梯阶数n:"))
way=0
for i in range(0,n+1):#一次一阶
    for j in range(0,n+1):#一次两阶
        if (i+2*j==n):
            way+=1
print(way,"种不同的方式")
          
        
