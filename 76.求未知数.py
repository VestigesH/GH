#题目：809*??=800*??+9*?? 其中??代表的两位数, 809*??为四位数，8*??的结果为两位数，9*??的结果为3位数。求??代表的两位数，及809*??后的结果。
for x in range(10,100):
    if 809*x==800*x+9*x and 809*x <10000 and 8*x <100 and 9*x<1000:
        print(x,"是??代表的两位数")
        print("809*??=",809*x)
        print()
