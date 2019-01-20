#题目：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
List1=[1,2,3,4,5,6,7,8,9]
List2=[]
k=eval(input("输入非负数k:"))
n=len(List1)
for i in range(-k,n-k):
    List2.append(List1[i])
print(List2)








