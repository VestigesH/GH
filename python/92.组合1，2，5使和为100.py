#题目：如何组合1、2、5这三个数使其和为100.
for i in range(0,21):
    for j in range(0,51):
        for k in range(0,101):
            if 1*k+2*j+5*i==100:
                print("1*",k,"+2*",j,"+5*",i,"=100")
            else:
                break
            
