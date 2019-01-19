import datetime#引入函数模块
year,month,day=eval(input("please input the year,month and day:"))
x=datetime.date(year,month,day)
print(x.isoformat())#输出年-月-日的格式
print(x.weekday())#输出日期所在星期数(周几)



