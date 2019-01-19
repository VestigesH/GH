import datetime
hour,mintue,second,microsecond=eval(input("请输入小时,分钟,秒和毫秒:"))
x=datetime.time(hour,mintue,second,microsecond)
print(" ")#暂停一秒
#四种方法对时间格式化
print(x.__format__("%H:%M:%S"))#将时间转化成字符串对象，以指定格式输出
print(x.strftime("%H:%M:%S"))#方法同上
print(x.isoformat())#ISO标准输出时间
print(x.__str__())#只是获得时间的字符串
