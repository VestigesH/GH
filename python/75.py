#题目：给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
s=str(input("please input a str:"))
for i in s:
    if s.count(i)==1:
        print( s.find(i))
        break
else:
    print("-1")
