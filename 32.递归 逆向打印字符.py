#题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来
s=str(input("请输入五个字符:"))
def fac(n):
    if n==-1:
        return " "
    else:
        return s[n]+fac(n-1)
print(fac(4))
