#题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
L=[];sum=0;numetor=2;denominator=1
for i in range(1,21):
    x=numetor
    y=denominator
    sum=sum+(x/y)
    L.append((x,"/",y))
    numetor=x+y
    denominator=x
print(sum)
    
    
