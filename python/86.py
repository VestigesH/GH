#题目：有两个磁盘文件A和B,各存放一行字母,要求把这两个文件中的信息合并(按字母顺序排列), 输出到一个新文件C中。
fa=open("A.txt","rt")
x=fa.read()
fa.close()

fb=open("B.txt","rt")
y=fb.read()
fb.close()

fc=open("C.txt","w")
L=list(x+y)
fc.writelines(L.sort())
fc.close
