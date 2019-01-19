#题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
n=str(input("请输入一个正整数:"))
w=len(n)
List=list(n)
i="".join(List)
List.reverse()  
print(w,"位数")
print(i)
    
