score=eval(input("请输入学生成绩： "))
if 90<=score<=100:
    print("A")
else:
    if 60<=score<=89:
        print("B")
    elif 0<=score<60:
        print("C")
    else:
        print("输入错误")
