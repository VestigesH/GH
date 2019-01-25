#45题目：两个 3 行 3 列的矩阵，实现其对应位置的数据相加，并返回一个新矩阵
s1=eval(input("请输入第一个3行3列矩阵:"))
L1=list(s1)
s2=eval(input("请输入第二个3行3列矩阵:"))
L2=list(s2)
L=[[0,0,0],[0,0,0],[0,0,0]]
for i in range(3):
    for j in range(3):
        L[i][j]=L1[i][j]+L2[i][j]
for k in L:
    print(k)
        
