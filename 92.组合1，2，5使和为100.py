#题目：如何组合1、2、5这三个数使其和为100.
for i in range(21):
    for j in range(51):
        for k in range(101):
            if 1*k+2*j+5*1==100:
                print("1*",k,"+2*",j,"+5*",i,"=100")
