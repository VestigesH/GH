def getcount(x):
    str=bin(x)
    count=str.count("1")
    return count

 
x=eval(input("please input a integer:"))
count=getcount(x)
print(count)
            
    
