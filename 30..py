#题目：给定一个整数数组，判断是否存在重复元素。如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
def isdifferent(str):#判断是否为重复元素，是返回True,否返回False
    list1=list(str)
    for i in list1:    
         n=list1.count(i)#确定每个元素在其序列里出现的次数
         if n >=2:
            return True
         if n==1:
            return False
            



s=str(input("请输入一组整数:"))
print(isdifferent(s))
            
        
    
