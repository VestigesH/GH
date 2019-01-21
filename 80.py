#题目：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
a=[0,2,3,4,5,0,6,0,7]
k=0
for i in range(len(a)):
    if a[k]==0:
        a.append(a.pop(k))
    else:
        k+=1
print(a)

     
    
