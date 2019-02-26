#题目：编写input()和output()函数输入，输出5个学生的数据记录。
list=[]
def Input(list):
    for i in range(5): 
        print("请输入第%d个学生的数据记录："%(i+1))
        num=input("请输入学号：")
        name=input("请输入姓名：")
        score=input("请输入成绩：")
        list.append(num)
        list.append(name)
        list.append(score)
def output(list):
    print("学生数据记录如下：")
    for j in list:
        print(j)

Input(list)
output(list)

        
