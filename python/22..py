#题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加由键盘控制。

a=eval(input("please input a:"))
i=eval(input("please input i:"))
num=0
list=[]
for i in range(0,i):
    num=num+a*(10**i)#分别算出a,aa,aaa......
    list.append(num)
    s=sum(list)
print("s=a+aa+aaa+aaaa+a...a=",s)
