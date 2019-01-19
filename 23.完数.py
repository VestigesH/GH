for x in range (1,1001):
    sum=0
    for i in range(1,x):
        if x%i==0:
            sum+=i
    if x==sum:
            print(x)
                 
                    
