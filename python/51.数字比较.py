#题目:数字比较
def compare(str):
    list=[]
    for i in range(len(str)):
        for j in str:
            list.append(j)
            list.sort()#默认为升序排列，若要降序，再使用list.reverse()
        return list

str=eval(input("请输入要比较的一组数:"))
list=compare(str)
print(list)


