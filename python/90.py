#题目：求一个字符串的所有排列
import itertools
s="Sun"
L=list(s)
J=list(itertools.permutations(L,3))
print(J)
