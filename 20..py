#20.	题目：写一个程序，输出从 1 到 n 数字的字符串表示。1. 如果 n 是3的倍数，输出“Fizz”；2. 如果 n 是5的倍数，输出“Buzz”；3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
n=eval(input("please input n:"))
for n in range(1,n+1):
    if n%3==0 and n%5!=0:
        print("Fizz")
    elif n%3!=0 and n%5==0:
        print("Buzz")
    elif n%3==0 and n%5==0:
        print("FizzBuzz")
    else:
        print(n)
