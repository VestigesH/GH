#题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。
letter1=str(input("please input the first letter:"))
if letter1=="M":
    print("Monday")
elif letter1=="W":
    print("Wednesday")
elif letter1=="F":
    print("Friday")
elif letter1=="T":
    letter2=str(input("please input the second letter:"))
    if letter2=="u":
        print("Tuesday")
    elif letter2=="h":
        print("Thursday")
    else:
        print(" Input error")
elif letter1=="S":
    letter2=str(input("please input the second letter:"))
    if letter2=="a":
        print("Saturday")
    elif letter2=="u":
        print("Sunday")
    else:
        print("Input error")
else:
    print("Input error")
        
