#题目：求一个3*3矩阵主对角线元素之和。
L=[[1,2,3],[4,5,6],[7,8,9]]
for i in L:
    print(i)
sum=0
for j in range(3):
    for k in range(3):
        x=L[j]
        y=x[k]
        if j==k:
            sum=sum+y
print("对角线之和为",sum)
