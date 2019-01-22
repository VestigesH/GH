#题目：从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件"test"中保存。
s=str(input("please input str:"))
fp=open("test.txt","w")
fp.write(s.upper())
fp.close()
