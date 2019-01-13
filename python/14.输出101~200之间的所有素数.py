counter=0
for n in range (101,200):
    for i in range(2,n):
        if n%i==0:
            break
    else:
        counter=counter+1
        print(n)
print(counter)
