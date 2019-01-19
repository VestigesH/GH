for x in range (1,1001):
    a_list=[]
    for i in range (1,x):
        if x%i==0:
            
            a_list.append(i)
            i=i+1
            if x==i:
                print(x)
                 
                    
