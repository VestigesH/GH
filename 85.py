#题目：给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素
l=[1,2,3,4,5,4,3,2,1]
for i in l:
    if l.count(i)==1:
        print(i)
