a_list=[1,1]
while len(a_list)<100:
        a_list.append(a_list[-2]+a_list[-1])
print(a_list)
