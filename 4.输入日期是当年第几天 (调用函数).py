from datetime import date#导入datetime模块中的date函数
year,month,day=eval(input("请输入年月日:"))
days=date(year,month,day)-date(year-1,12,31)#和所输入日期的去年最后一天相差数即为所输入日期当年第几天天数
print(days)
