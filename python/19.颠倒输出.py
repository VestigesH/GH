n=eval(input("please input a integer:"))
str=bin(n)
a_list=[]
a_list=list(str)
for i in range(1,3):
    del a_list[0] 
a_list.reverse()
for i in a_list:
    print(i,end=" ")
