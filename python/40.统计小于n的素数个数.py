n=int(input("请输入非负整数n:"))
i=1
j=2
counter=0
for i in range(1,n):
    i=i+1
    for j in range(2,i):
       if (i%j==0):
           j=j+1
           break
    else:
        counter=counter+1
print(counter)

