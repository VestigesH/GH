counter=0
num=int(input("请输入非负整数n:" ))
for i in range(2,num):
    if num<2:
        print("0")
    elif num==2:
        print("1")
    elif num%i==0:
        break
else:
    num=num+1
    counter=counter+1
print()
print(counter)
    
