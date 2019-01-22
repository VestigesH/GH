#题目：从键盘输入一些字符，逐个把它们写到磁盘文件上，直到输入一个 # 为止。
s=str(input("请输入一些字符:"))
fp=open("file.txt","w")
for i in s:
    if i=="#":
        break
    else:
        fp.write(i)
fp.close()
