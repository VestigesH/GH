#题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
s=str(input("请输入一行字符:"))
letter=0;blank=0;number=0;other=0
for i in s:
    if i.isalpha():
        letter=letter+1
    elif i==" ":
        blank=blank+1
    elif i.isdigit():
        number=number+1
    else:
        other=other+1
print("英文字母个数为:",letter,"\n","空格数为:",blank,"\n","数字个数为:",number,"\n","其他字符个数为:",other)
        
