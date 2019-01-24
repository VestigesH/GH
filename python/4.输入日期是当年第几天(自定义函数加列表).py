def is_leap_year(year): # 判断年份是否为闰年，是返回True，否则返回False
  if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
    return True
  else:
    return False
  
def function(year, month, day): # 计算给定日期是那一年的第几天
    leap_year = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    no_leap_year = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if is_leap_year(year):
        result = sum(leap_year[:month - 1]) + day
    else:
        result = sum(no_leap_year[:month - 1]) + day
    return result

  

year,month,day=eval(input("请输入年,月,日:"))
result=function(year,month,day)
print(result)
