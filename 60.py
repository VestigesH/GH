#题目：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转
n=int(input("请输入整数:"))
n=str(n)
if len(n)==1:
   print(int(n))
if n[0]!="-":
    n= n[::-1]
    n= int(n)
else:
    n= n[1:][::-1]
    n= int(n)
    n= -n
if -2147483648<n<2147483647:
    print(n)
else:
    print("数值溢出")

