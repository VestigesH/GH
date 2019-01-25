#题目：读取7个数（1—50）的整数值，每读取一个值，程序打印出该值个数的＊
a=0
while a<7:
        n=int(input("please input n:"))
        if 1<=n<=50:
                print(n*"*",end="")
                print("\n")
                a+=1
        

