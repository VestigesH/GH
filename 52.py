#题目：取一个整数a从右端开始的4〜7位。
a=int(input("input a:"))
print((a>>3)&(~(0<<4)))
