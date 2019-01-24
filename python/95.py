#题目：给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数
s1_set={2,3,4,5,6,7,8,10}
s2_set={" "}
n=int(input("please input n:"))
for i in range(n+1):
    s2_set.add(i)
print(s2_set-s1_set)
    
    

