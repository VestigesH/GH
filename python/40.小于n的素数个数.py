n=int(input("请输入n:"))
counter=0
for i in range(2,n):
    for j in range(2,i):
       if (i%j==0):
           break
    else:
        counter=counter+1
print(counter)
