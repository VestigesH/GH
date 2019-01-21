#题目：给定两个数组，编写一个函数来计算它们的交集

x=[1,2,3,4,5]
y=[4,5,6,7,8]
z=[]
for i in x:
    for j in y:
        if i==j:
            z.append(i)
print(z)
                
