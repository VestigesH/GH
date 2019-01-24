#题目：python字典按照value进行排序
dict={"x":1,"y":2,"z":3}
D= zip(dict.values(),dict.keys())
print(sorted(D))
