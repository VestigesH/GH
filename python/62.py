#题目：输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。
s=eval(input("输入一组数:"))
L=list(s)
M=max(L)
m=min(L)
x=L.index(M)
y=L.index(m)
L[x]=L[0]
L[0]=M
L[y]=L[-1]
L[-1]=m
print(L)



